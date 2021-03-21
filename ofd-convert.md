#### 上传OFD在线转PNG,SVG-服务更新时间(20210119)
<form name="ofd" action="http://api.myofd.cn/ofd-convert?otype=svg&dtype=file&dindex=0" enctype='multipart/form-data' method='POST' target="_blank">
     <input type="file" accept=".ofd" name="file" style="display:none" onchange="upload.click()" >
     <input type="button" onclick="file.click()" style="width:100%" value="单击选择OFD文档开始转换"/>
     <button type="submit" name="upload" style="display:none">上传</button>
</form>
<form name="ofd" action="http://api.myofd.cn/ofd-convert?otype=svg&dtype=file&dindex=0" enctype='multipart/form-data' method='POST' target="iframeout">
     <input type="file" accept=".ofd" name="file" style="display:none" onchange="document.all.iframeout.style.display='';upload.click()" >
     <input type="button" onclick="file.click()" style="width:100%" value="单击选择OFD文档开始转换"/>
     <button type="submit" name="upload" style="display:none">上传</button>
</form>
<iframe width="100%" height="120" id="iframeout" name="iframeout" style="display:none"></iframe>
~~~json
// 返回值 JSON格式
{
    "status": 0,  // 0成功
    "speed": 120, // 处理时间,单位毫秒
    "data": "http://api.myofd.cn/ofd-process/0050090931.ofd"
}
~~~

~~~html
<form name="ofd" enctype="multipart/form-data" action="http://api.myofd.cn/ofd-convert?otype=svg&dtype=file" method="post" target="_blank">
    <input type="file" name="file1">
    <input type="submit" name="submit" value="转换" οnclick="javascript:document.ofd.submit();">
</form>
~~~

##### OFD转换接口功能描述
~~~
上传OFD文档转换为PNG,SVG,为了效率,上传方式为form提交
otype 转换后的文件类型
dindex 转换第几页(转换PNG,SVG时有效),默认从0开始，0代表第1页,2代表第2页等
dtype 等于file时,如果转换成功,会直接输出为文件流,如果没有dtype参数,默认是输出json格式,文件会暂存在服务器,通过data的地址下载,出错时也返回json格式
~~~

##### OFD转换测试接口地址
~~~
http://api.myofd.cn/ofd-convert?otype=svg|png&dtype=file&dindex=0
~~~

##### 参考代码
[转换本地接口封装源码及可执行程序](/381.html "转换本地接口封装源码(curl)")
[电子印章格式封装源码(Openssl封装)](/369.html "电子印章格式封装C源码")

***

#### 20210320
~~~
1. ofd格式解析,zip格式优化,支持不规范的格式
~~~

#### 20210210
~~~
1. 资源查找方式优化（嵌套,集合）
2. 验签和验章的接口优化,封装统一（支持pkcs7,sm2的消息语法规范,印章的多种版本,根证书的验证）
~~~

#### 20210202
~~~
1. 添加印章的验证,如果验证失败,章的图片将为黑白

#### 20210127
~~~
1. text对象的glyphs解析,如果有glyphs直接使用,没有根据文字查找gid
2. 自定义内嵌字体的解析,根据glyphs直接使用
~~~

#### 20210120
~~~
1. 添加注释内容路径解析,支持各种方式,包含水印,路径,高亮等
~~~

#### 20210119
~~~
1. 添加注释解析(参考板式文档规范)(支持水印,包含其他基本内容对象的解析)
2. 复合对象,优化调整,主要是针对复合对象内容的坐标计算方式
3. 裁剪增对图片优化,调整
3. 印章格式解析优化,支持各种版本的格式解析
~~~

#### 20210117
~~~
1. 添加签名,印章数据解析,参考规范(安全电子签章密码技术规范 GM/T 0031 2014 | GB∕T 38540-2020)[格式封装代码](http://www.tohack.com/369.html)
2. 印章图片数据格式解析支持(jpg,png,gif,bmp,jb2,ofd)
~~~
#### 20210114
~~~
1. ofd模板解析bug,导致渲染多个模板
2. 解析DrawParam参数,找不到参数时,忽略掉
3. text的deltax坐标问题,如果后面参数错误,默认按上一个的值处理(有的ofd格式不按标准做的)
~~~
#### 20210113
~~~
1. path的剪切ctm小数位精度调整,坐标优化修改
~~~
#### 20210112
~~~
1. text文字对象glyphs的优化处理（对一些未知字体还是有问题）
2. text,path,clip对象,增对stroke的内存优化
~~~
#### 20210110
~~~
1. composite复合对象ctm处理修改
2. 添加text文字对象glyphs的处理
~~~
#### 20210108
~~~
1. 文字ctm偏移修改
~~~
#### 20210106
~~~
1. 图片剪切path修改
~~~
#### 20201230
~~~
1.增加clip的处理
2.透明度参数的优化处理
~~~
#### 20201228
~~~
1.增对path的ctm调整线的宽度
~~~
#### 20201225
~~~
1.增加增对各种图像格式的mask处理
~~~
#### 20201221
~~~
1.字体文件查找优化修改
~~~
#### 20201219
~~~
1.资源路径读取修改,读取失败异常处理
2.转png出现mask有问题(未解决)
~~~
#### 20201218
~~~
1.OFD文档转换服务正式上线,支持可转换的格式PNG,SVG
2.字体解析修改
~~~

