## Voro-for-MATLAB
using mex to apply voro++ in MATLAB<br>
使用mex在MATLAB中调用voro++<br>
 voro++:http://math.lbl.gov/voro++/ <br>
 mex:https://ww2.mathworks.cn/help/matlab/ref/mex.html <br>

# 安装
for MATLAB
**Necessary：<br>
 MinGW-4.9.2 <br>
 TDM-GCC** <br>


# 使用

  ```matlab
  mex voro_cmd.cpp src/voro++.cc <br>
  voro_cmd(voro++,[opts],<x_min>,<x_max>,<y_min>,<y_max>,<z_min>,<z_max>,<filename>); <br>
  ```
try the demo in matlab:<br>
  ```matlab
  mex voro_cmd.cpp src/voro++.cc %编译
  voro_cmd('voro++','-r','-o','-c','%i %q %r;%t;%P;%n;%l','0','100','0','100','0','100','input2.txt');%voro++的cmd命令
  ```
 
Voro++ command-line utility reference: http://math.lbl.gov/voro++/doc/cmd.html <br>
Voro++ customized output reference : http://math.lbl.gov/voro++/doc/custom.html <br>

