function x = gaussElimination(A, b)
    n = size(A, 1);
    Aug = [A, b]; % Genişletilmiş katsayı matrisi

    % İleri eleme aşaması
    for k = 1:n-1
        % Pivoting
        [~, pivot] = max(abs(Aug(k:n, k))); % Sütundaki maksimum elemanın indisini bulur
        pivot = pivot + k - 1; % İndisi düzeltir
        if pivot ~= k
            Aug([k, pivot], :) = Aug([pivot, k], :); % Pivot satırını üst sıraya taşır
        end

        % Eleme
        for i = k+1:n
            factor = Aug(i, k) / Aug(k, k); % Eleme faktörü hesaplanır
            Aug(i, :) = Aug(i, :) - factor * Aug(k, :); % Eleme işlemi yapılır
        end
    end

    % Geriye doğru substitüsyon aşaması
    x = zeros(n, 1);
    x(n) = Aug(n, n+1) / Aug(n, n); % Son denklem doğrudan çözülür
    for i = n-1:-1:1
        x(i) = (Aug(i, n+1) - Aug(i, i+1:n) * x(i+1:n)) / Aug(i, i); % Diğer denklemler substitüsyon ile çözülür
    end
end
