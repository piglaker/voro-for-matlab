## voro-for-matlab
using mex to apply voro++ in matlab
使用mex在matlab中调用voro++
# voro++:http://math.lbl.gov/voro++/
# mex:https://ww2.mathworks.cn/help/matlab/ref/mex.html

try... in matlab:
mex voro_cmd.cpp src/voro++.cc%编译
voro_cmd('voro++','-r','-o','-c','%i %q %r;%t;%P;%n;%l','0','100','0','100','0','100','input2.txt');%voro++的cmd命令
