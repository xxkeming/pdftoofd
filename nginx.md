## 服务器部署配置说明
***

##### 参考DEMO下载地址
> https://github.com/xxkeming/pdftoofd

##### 服务器配置说明
~~~c
Nginx服务器默认启动方式: ./nginx -c conf/nginx.conf
配置说明: 具体参考conf目录里的nginx.conf
~~~

~~~c
//处理pdf转ofd的插件模块
location @ofd_convert_from_upload {
    ofd_convert_from_upload; 
}

//接收上传的处理
location /upload {
    // 上传完之后转交给插件处理
    upload_pass @ofd_convert_from_upload;

    // 上传文件存储的目录
    upload_store html/ofd-process/;

    // 上传文件的权限配置
    upload_store_access user:rw group:rw all:rw;

    upload_add_header "upload_path" $upload_tmp_path;

    // 上传失败返回的错误码
    upload_cleanup 400 404 499 500-505;
}
~~~

##### 参考DEMO下载地址
> https://github.com/xxkeming/pdftoofd
