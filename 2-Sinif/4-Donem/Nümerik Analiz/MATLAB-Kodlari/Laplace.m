function determinant = Laplace(A)
    [m, n] = size(A);
    
    if m ~= n
        error('Matris kare olmalıdır.');
    end
    
    if n == 1
        determinant = A(1, 1);
    else
        determinant = 0;
        for j = 1:n
            B = A;
            B(1, :) = [];
            B(:, j) = [];
            C = (-1)^(1+j) * Chio(B);
            determinant = determinant + A(1, j) * C;
        end
    end
end