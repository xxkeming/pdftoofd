## 板式文档转换接口-更新时间(20201219)

#### PDF转换API调用接口地址
~~~html
<form name="pdf" enctype="multipart/form-data" action="http://api.tohack.com/pdf-convert?otype=svg" method="post" target="_blank">
    <input type="file" name="file1">
    <input type="submit" name="submit" value="PDF转换OFD" οnclick="javascript:document.pdf.submit();">
</form>
~~~
~~~json
// 返回值
{
    "status": 0,  // 0成功
    "speed": 120, // 处理时间,单位毫秒
    "data": "http://api.tohack.com/pdf-process/0050090931.ofd"
}
~~~

##### PDF转换接口功能描述
>上传PDF文档转换为OFD,PNG,SVG,为了效率,上传方式为form提交

##### PDF转换测试接口地址
>http://api.tohack.com/pdf-convert?otype=ofd|svg|png


***
#### OFD转换API调用接口地址
~~~html
<form name="ofd" enctype="multipart/form-data" action="http://api.tohack.com/ofd-convert?otype=svg" method="post" target="_blank">
    <input type="file" name="file1">
    <input type="submit" name="submit" value="转换" οnclick="javascript:document.ofd.submit();">
</form>
~~~
~~~json
// 返回值
{
    "status": 0,  // 0成功
    "speed": 120, // 处理时间,单位毫秒
    "data": "http://api.tohack.com/ofd-process/0050090931.svg"
}
~~~

##### OFD转换接口功能描述
>上传OFD文档转换为PNG,SVG,为了效率,上传方式为form提交

##### OFD转换测试接口地址
>http://api.tohack.com/ofd-convert?otype=svg|png