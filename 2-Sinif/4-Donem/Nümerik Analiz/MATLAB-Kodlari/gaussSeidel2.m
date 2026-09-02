function x = gaussSeidel2(A, b, initialGuess, epsilon)
    n = size(A, 1);
    x = initialGuess;
    error = epsilon + 1;

    while error > epsilon
        x_old = x;

        for i = 1:n
            sigma = 0;

            for j = 1:n
                if j ~= i
                    sigma = sigma + A(i, j) * x(j);
                end
            end

            x(i) = (b(i) - sigma) / A(i, i);
        end

        error = norm(x - x_old);
    end
end
