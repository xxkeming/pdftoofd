#### 上传OFD转PNG,SVG-服务更新时间(20210112)
<form name="ofd" action="http://api.tohack.com/ofd-convert?otype=svg" enctype='multipart/form-data' method='POST' target="iframeout">
     <input type="file" accept=".ofd" name="file" style="display:none" onchange="document.all.iframeout.style.display='';upload.click()" >
     <input type="button" onclick="file.click()" style="width:100%" value="单击选择OFD文档开始转换"/>
     <button type="submit" name="upload" style="display:none">上传</button>
</form>
<iframe width="100%" height="120" id="iframeout" name="iframeout" style="display:none"></iframe>

~~~json
// 返回值
{
    "status": 0,  // 0成功
    "speed": 120, // 处理时间,单位毫秒
    "data": "http://api.tohack.com/ofd-process/0050090931.ofd"
}
~~~

~~~html
<form name="ofd" enctype="multipart/form-data" action="http://api.tohack.com/ofd-convert?otype=svg" method="post" target="_blank">
    <input type="file" name="file1">
    <input type="submit" name="submit" value="转换" οnclick="javascript:document.ofd.submit();">
</form>
~~~

##### OFD转换接口功能描述
~~~
上传OFD文档转换为PNG,SVG,为了效率,上传方式为form提交
~~~

##### OFD转换测试接口地址
~~~
http://api.tohack.com/ofd-convert?otype=svg|png
~~~

***
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

