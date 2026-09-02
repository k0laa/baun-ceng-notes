clc, clear all, close all;
%Gauss Seidel
%Ax=c

A = [8 1 -1; -1 -3 2; 2 1 9];
c = [8 -4 12];
start = [0 0 0];
eps_s = 10^(-5);


n=size(c,1);
x=randi([-10 10],n,1);
x_old=x;
MAX_ITER=100;


fprintf('ite \txold(1) \tx(1) \t eps_a(1) \t xold(2) \tx(2) \teps_a(2) \txold(3) \tx(3) \t eps_a(3) \txold(4) \tx(4) \teps_a(4)');
fprintf('\n')
for k=1:MAX_ITER

 for i=1:n
 toplam=0;
 for j=1:n
 if i~=j
 toplam=toplam+A(i,j)*x(j);
 end
 end

 x(i)=(c(i)-toplam)/A(i,i);
 eps_a(i)=abs((x(i)-x_old(i))/x(i));
 end

EPS_A=max(eps_a);
x_old=x;
if EPS_A<eps_s
 break;
end
end