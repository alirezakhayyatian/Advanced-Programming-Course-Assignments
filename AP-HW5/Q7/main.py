#b=[1, 2 ,3 ,4 ,5 ,12 ,7 ,8, 9, 12, 18, 6]
#print(' '.join((str(y)) for y in(sorted(set(  [i for i in b if i%6==0 and b.index(i)%6==5  ] )  ) )))

print (' '.join(str(y)for y in  (sorted(set( [j for (i,j) in enumerate([int(x) for x in input('what is your array:').split()]) if i%6==5 and j%6==0  ] )  ) )))


