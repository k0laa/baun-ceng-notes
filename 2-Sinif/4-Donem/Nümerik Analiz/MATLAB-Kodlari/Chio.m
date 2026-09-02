%Chio
function d = Chio(A)
    [n, m] = size(A);
    if n ~= m
        error('Matris kare olmalıdır.');
    end
    
    if n == 1
        d = A(1,1);
        return;
    end
    
    % Eğer (1,1) elemanı sıfırsa, satır değiştir
    if A(1,1) == 0
        for i = 2:n
            if A(i,1) ~= 0
                A([1 i], :) = A([i 1], :); % satırları değiştir
                break;
            end
        end
    end
    
    if A(1,1) == 0
        d = 0;
        return;
    end
    
    % Yeni matris B'yi oluştur (Chio indirgeme matrisini)
    B = zeros(n-1);
    for i = 2:n
        for j = 2:n
            B(i-1,j-1) = A(1,1)*A(i,j) - A(i,1)*A(1,j);
        end
    end
    
    % Determinant hesabı (recursive)
    d = ((-1)^(0)) * (1 / (A(1,1)^(n-2))) * Chio(B);
end
