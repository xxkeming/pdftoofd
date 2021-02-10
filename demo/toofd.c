#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <time.h>
#include <math.h>

//#include <unistd.h>
#include <fcntl.h>

#define CURL_STATICLIB
#include <curl/curl.h>
#include <curl/easy.h>

#include <openssl/bio.h>

#ifdef _MSC_VER
#define strcasecmp stricmp
#endif

static size_t 
url_write_data(void *data, size_t size, size_t nmemb, void *userp)
{
    return BIO_write((BIO*)userp, data, (int)(size * nmemb));
}

static int 
url_access(const char *url, BIO *in, BIO *out)
{
    CURLcode retval = CURLE_FAILED_INIT; 
    CURL *curl = NULL;  

    struct curl_httppost *formpost = NULL;  
    struct curl_httppost *lastptr = NULL;

    const char *data = NULL;
    int data_len;

    curl = curl_easy_init();

    if (curl) {
        //curl_easy_setopt(curl, CURLOPT_VERBOSE, 1);

        curl_easy_setopt(curl, CURLOPT_URL, url);
        
        //curl_formadd(&formpost, &lastptr, CURLFORM_COPYNAME, "filename", CURLFORM_FILE, file, CURLFORM_END);

        // 内存形式
        if (in != NULL) {
            data_len = BIO_get_mem_data(in, &data);
            curl_formadd(&formpost, &lastptr, CURLFORM_COPYNAME, "filename", CURLFORM_BUFFER, "file", CURLFORM_BUFFERPTR, data, CURLFORM_BUFFERLENGTH, (long)data_len, CURLFORM_END);
        }

        curl_easy_setopt(curl, CURLOPT_HTTPPOST, formpost);

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, url_write_data);

        BIO_reset(out);
	    curl_easy_setopt(curl, CURLOPT_WRITEDATA, out);

        //curl_easy_setopt(curl, CURLOPT_HTTPHEADER, "Accept-Encoding:gzip");

        curl_easy_setopt(curl, CURLOPT_ENCODING, "gzip");

        retval = curl_easy_perform(curl);
        if (retval != CURLE_OK)
            printf("curl_easy_perform() failed: %s\n", curl_easy_strerror(retval));

        curl_formfree(formpost);

        curl_easy_cleanup(curl);
    }
    return retval;
}

int main(int argc, char *argv[])
{
    BIO *in = NULL, *data = NULL, *out = NULL;

    const char *p = NULL, *o = NULL;
    int retval = 0, len;
    char tmp[8192];

    curl_global_init(CURL_GLOBAL_ALL);

    char url[512] = { 0 };

    p = strrchr(argv[1], '.');
    if (strcasecmp(p, ".ofd") != 0 && strcasecmp(p, ".pdf") != 0) {
        printf("file error (ofd or pdf)\n");
        goto error;
    }

    o = strrchr(argv[2], '.');
    o = (o == NULL) ? argv[2] : o + 1;

    if (strcasecmp(p, ".ofd") == 0 && (strcasecmp(o, "svg") != 0 && strcasecmp(o, "png") != 0)) {
        printf("file ofd out error, out file(svg or png)\n");
        goto error;
    }

    if (strcasecmp(p, ".pdf") == 0 && (strcasecmp(o, "ofd") != 0 && strcasecmp(o, "svg") != 0 && strcasecmp(o, "png") != 0)) {
        printf("file pdf out error, out file(ofd or svg or png)\n");
        goto error;
    }
    
    sprintf(url, "http://api.myofd.cn/%s-convert?otype=%s&dtype=%s", strcasecmp(p, ".ofd") == 0 ? "ofd": "pdf", o, o == argv[2] ? "json" : "file");

    in = BIO_new(BIO_s_file());
    if (BIO_read_filename(in, argv[1]) <= 0) {
        printf("read %s error\n", argv[1]);
        goto error;
    }
    
    data = BIO_new(BIO_s_mem());
    while(BIO_write(data, tmp, BIO_read(in, tmp, 8192)));
    BIO_free(in);

    out = BIO_new(BIO_s_mem());
    if (url_access(url, data, out) != 0) {
        printf("url access error\n");
        goto error;
    } 

    len = BIO_get_mem_data(out, &p);

    if (o == argv[1] || p[0] == '{') {
        memcpy(tmp, p, len);
        tmp[len] = '\0';
        printf("%s\n", tmp);
    } else {
        BIO *outf = BIO_new(BIO_s_file());
        BIO_write_filename(outf, argv[2]);
        BIO_write(outf, p, len);
        BIO_free(outf);
    }
    goto cleanup;
error:
    retval = 1;
    printf("doc2 xxx.ofd (xxx.svg | xxx.png)\n");
    printf("doc2 xxx.pdf (xxx.ofd | xxx.svg | xxx.png)\n");
cleanup:
    BIO_free(data);
    BIO_free(out);
    curl_global_cleanup();
    return retval;
}


/*
http://url-addr/upload

// 返回值
{
	"status": 0,
	"data": "http://124.70.184.141/ofd-process/0050090931.ofd"
}
*/