x=[1,1.8,1.8,1];
n=length(x);
fs=8;
dt=1/fs;
ti=0:dt:(n-1)*dt;
nfft=8;
y=fft(x,nfft);
df=fs/nfft;
fi=0:df:(nfft-1)*df;

subplot(312)
plot(fi,real(y))
title('real')
xlabel('f(Hz)')
subplot(313)
plot(fi,imag(y))
title('imag')
xlabel('f(Hz)')
x_ifft=ifft(y);
x_ifft_output=(x_ifft(1:n));
subplot(311)
plot(ti,x_ifft_output)
title('x(t)')
xlabel('t(s)')

figure
%Determin Nyquist frequency:
Nyq=fs/2;
%Save frequency array:
fi_array=(-Nyq:df:Nyq-df);%fftshift()后的频率 （0点右移Nyq个点！！）
y_shift=fftshift(y);
subplot(312)
plot(fi_array,real(y_shift))
title('real')
xlabel('f(Hz)')
subplot(313)
plot(fi_array,imag(y_shift))
title('imag')
xlabel('f(Hz)')
subplot(311)
plot(ti,x)
title('x(t)')
xlabel('t(s)')