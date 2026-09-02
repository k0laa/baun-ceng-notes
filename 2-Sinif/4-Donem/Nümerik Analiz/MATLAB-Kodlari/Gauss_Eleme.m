function det_val = Gauss_Eleme(C)
    n = size(C, 1);
    det_val = 1;

    for k = 1:n-1
        [~, pivot] = max(abs(C(k:n, k)));
        pivot = pivot + k - 1;
        if pivot ~= k
            C([k, pivot], :) = C([pivot, k], :);
            det_val = -det_val; % Satır değişimi yapıldığında işaret değişir
        end

        for i = k+1:n
            factor = C(i, k) / C(k, k);
            C(i, k:n) = C(i, k:n) - factor * C(k, k:n);
        end
    end

    % Determinant hesabı
    for i = 1:n
        det_val = det_val * C(i, i);
    end
end
