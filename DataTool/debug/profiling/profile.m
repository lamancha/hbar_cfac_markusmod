A=load('profile.tsv');
semilogy(A(A(:,1)==3,2), A(A(:,1)==3,3),'k');
hold on;
semilogy(A(A(:,1)==2,2), A(A(:,1)==2,3),'g');
semilogy(A(A(:,1)==1,2), A(A(:,1)==1,3),'b');
title('Time consumption for generating decay table, one field point');
legend('3 orbitals', '2 orbitals', '1 orbital', 'Location', 'Northwest');
ylabel('Time (ms)');
xlabel('# energy levels');
print -dpdf profile.pdf