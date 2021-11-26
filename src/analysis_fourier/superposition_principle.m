a=[zeros(1,2), 1.5*ones(1,4), zeros(1,32)];
c=[zeros(1,20), −0.5*ones(1,4), zeros(1,14)];
e1=a+c;
coef=0.35;
b(1)=0;
for k=2 : 38; b(k)=a(k)−coef*b(k−1); end
13
d(1)=0;
for k=2 : 38; d(k)=c(k)−coef*d(k−1); end
f(1)=0;
for k=2 : 38; f(k)=e1(k)−coef*f(k−1); end
yt(1)=0;
for k=1 : 38; yt(k)=b(k)+d(k); end
subplot(3,2,1); plot(a); axis([0 40 −1 2]);
subplot(3,2,2); plot(b); axis([0 40 −1 2]);
subplot(3,2,3); plot(c); axis([0 40 −1 2]);
subplot(3,2,4); plot(d); axis([0 40 −1 2]);
subplot(3,2,5); plot(e1); axis([0 40 −1 2]);
subplot(3,2,6); plot(f); axis([0 40 −1 2]);
text(−50,6.7,'(a)')
text(3.0,6.7,'(b)')
text(−50,2.5,'(c)')
text(3.0,2.5,'(d)')
text(−50,−1.6,'(e)')
text(3.0,−1.6,'(f)')