%%内点法
%定义函数和约束
clear all;
clc;
syms x1 x2 %
f=x1+2*x2;  %
g1=-x1^2+x2%
g2=x1     %
G1=@(x,y) -x^2+y; %
G2=@(x,y) x;  %


R=1; %
C=0.1; %
eps=0.0001;%
X=[0,0];
S=[0,0];%
k=0;  %
max_ite=500;
B=f-R*(log(g1)+log(g2));  %
G=@(x,y) R*sum( [log(G1(x,y)),log(G2(x,y))]); %

%B=f+R*(1/g1+1/g2);  %
%G=@(x,y) R*sum( [1/G1(x,y),1/G2(x,y)]); %

%%
%迭代
while true
    k=k+1;
    if k>max_ite 
        break;
    end

    B=f-R*(log(g1)+log(g2));
    G=@(x,y) R*sum( [log(G1(x,y)),log(G2(x,y))]);
    Dao1=diff(B,'x1');
    Dao2=diff(B,'x2');

    [x,y]=solve(Dao1==0,Dao2==0);
    if length(x)>1 
         if G1( x(1,1),y(1,1) )>=0  && G2( x(1,1),y(1,1) )>=0
            S=[x(1,1),y(1,1)];
         elseif G1( x(2,1),y(2,1) )>=0  && G2( x(2,1),y(2,1) )>=0
            S=[x(2,1),y(2,1)];
         end
    else
        S=[x,y];
    end
    S=double(S);
    r=abs(G(S(1,1),S(1,2)));
    if r==Inf 
        break;
    end
    if r<=eps
        X=S;
        break;
    else 
        R=R*C;
    end
end

fprintf('The best solution is:\n');
fprintf('x1=');disp(X(1,1));
fprintf('x2=');disp(X(1,2));

fprintf('The number of iteration is :');
fprintf('k=');
disp(k);

fprintf('r=');
disp(r);
r=0;


