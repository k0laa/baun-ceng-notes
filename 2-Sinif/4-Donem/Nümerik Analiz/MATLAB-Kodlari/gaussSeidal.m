function x = gaussSeidal(A, b, x0, epsilon)
    n = length(b);
    x = x0;
    error = epsilon + 1;

    while error > epsilon
        x_prev = x;

        for i = 1:n
            sum1 = A(i, 1:i-1).*x(1:i-1);
            sum2 = A(i, i+1:n).*x_prev(i+1:n);

            x(i) = (b(i) - sum1 - sum2) / A(i, i);
        end

        error = norm(x - x_prev, inf);
    end
end
