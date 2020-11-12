## PDF板式文档转OFD板式文档
<form enctype="multipart/form-data" action="http://124.70.184.141/upload" method="post">
  <input type="file" name="file1"><br>
  <input type="submit" name="submit" value="PDF转换OFD">
</form>

***
#### API调用接口地址
服务器部署程序及用例: https://github.com/xxkeming/pdftoofd
配置说明: 具体参考conf目录里的nginx.conf
```
#处理pdf转ofd的插件模块
location @ofd_convert_from_upload {
    ofd_convert_from_upload; 
}
#接收上传的处理
location /upload {
    upload_pass @ofd_convert_from_upload;
    upload_store html/ofd-process/;
    upload_store_access user:rw group:rw all:rw;
    upload_add_header "upload_path" $upload_tmp_path;
    upload_cleanup 400 404 499 500-505;
}
```
测试服务器地址: http://124.70.184.141/upload
POST Form 上传PDF文件 http://url-addr/upload
```
<form enctype="multipart/form-data" action="/upload" method="post">
    <input type="file" name="file1"><br>
    <input type="submit" name="submit" value="PDF转换OFD">
</form>
```
```
// 返回值
{
    "status": 0,  // 0成功
    "speed": 120, // 处理时间,单位毫秒
    "data": "http://url-addr/ofd-process/0050090931.ofd"
}
```

***
#### 20201107
    1.pdf图层优化,增对透明的放到背景层
    2.path增对ctm缩放线宽的调整
#### 20201106
    1.pdf图层分租分块的处理
#### 20201105
    1.clip优化
    2.文字的clip
#### 20201101
    1.颜色渐变转图片
    2.path的clip增对图片的
    3.优化boundry,图片参数优化
#### 20201031
    1.text优化(多行排版),坐标等浮点类型保留4位小数
#### 20201028
    1.text处理优化,删除一些没用的字
    2.image旋转处理优化
#### 20201026
    1.text和path的stroke参数调整(linewidth和miterlimit)
    2.image的mask处理,通过颜色生成图片(修改bug)
    3.添加渐变生成图片
#### 20201025
    1.text的y坐标优化处理
    2.image的mask(颜色生成图片处理)
#### 20201020
    1.文字boundary没有计算正确(已解决,text和path)
    2.文字没有hscale(已解决,text的变化,缩放等)
    3.渐变,裁剪没有
## OFD阅读器
***
## OFD数字签名,印章,签章,时间戳
***