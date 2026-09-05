%128x64 GLCD için Bitmap/BW donüştürme

k=1;m=1; level=0.5;
data0 = im2bw(res1, level); %res1: gorüntü dosyasının adı

for t=1:8:64

    for j=1:128

        for i=t:t+7
            data(m) = data0 (i,j);
            m=m+1;
        end

        resim0(k) = uint8 (bi2de (data));
        data=0;
        k=k+1;
        m=1;

    end
end

resim=bitcmp (resim0); %piksellerin terslenmesi