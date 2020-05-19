function [y] = mex2voro(L, Matrix_P, Matrix_W)
disp('mex2voro运行')

l = size(Matrix_P);
id = 1:1:l(2);

if min(size(Matrix_P)) < 3
    disp('平面上，进行全零填充')
    padding = zeros(1,l(2));
    Particle= [id', Matrix_P',padding', Matrix_W']';
else
    Particle= [id', Matrix_P', Matrix_W']';
end
disp('开始编译voro++')
mex test3dvoro.cpp src/voro++.cc

ZONE = [0 L 0 L 0 L]';
test3dvoro(ZONE, Particle,'%s %r % c');

disp('计算完毕')
disp('结果已保存');
disp('所有粒子（坐标&权重）保存在 particles.txt');
disp('voro_面向cell使用面顶点遍历面以及面的对应点 cell.txt');
end