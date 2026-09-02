clear; clc;

% Sekant Yöntemi girdileri
func = @(x) (x^2)/2 - sin(x);
x0 = 1.5;
x1 = 2;
tolerance = 0.05;
max_iterations = 100;

root = sekant(func, x0, x1, tolerance, max_iterations);
disp(root);


% newtonRaphson yöntemi girdileri
func = @(x) x^2 - 4;
derivative = @(x) 2 * x;
initial_guess = 1.5;
tolerance = 1e-6;
max_iterations = 100;

root = newtonRaphson(func, derivative, initial_guess, tolerance, max_iterations);
disp(root);



%Gaus Eliminasyon Yöntemi
A = [2 5 -3;7 2 -3;1 -1 -6];
b = [-31 -32 -23]

x = gaussElimination(A, b);
disp(x);

%Gaus Eliminasyon Yöntemi Determinant hesabı
C = [1 1 1 1 1;1 2 3 4 5;1 3 5 10 15;1 4 10 20 35;1 5 15 35 70];

%C = [1, 1, 1, 1, 1; 1, 2, 3, 4, 5; 1, 3, 5, 10, 15; 1, 4, 10, 20, 35; 1, 5, 15, 35, 70];
det_val = Gauss_Eleme(C);
disp(det_val);


A = [3 7 8 15; 2 6 5 11; 2 6 10 19; 4 11 19 88];
determinant = Chio(A);
disp(determinant);


