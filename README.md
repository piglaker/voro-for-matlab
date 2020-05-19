## voro-for-matlab
using mex to apply voro++ in matlab<br>
使用mex在matlab中调用voro++<br>
 voro++:http://math.lbl.gov/voro++/ <br>
 mex:https://ww2.mathworks.cn/help/matlab/ref/mex.html <br>

try... in matlab:<br>
mex voro_cmd.cpp src/voro++.cc <br>
voro_cmd('voro++','-r','-o','-c','%i %q %r;%t;%P;%n;%l','0','100','0','100','0','100','input2.txt');%voro++的cmd命令
