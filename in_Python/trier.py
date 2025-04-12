en=enumerate(["a", "b", "c"])
# try them one by one 
print(en)

# ok let's try to print it 
print(list(en))

# what is the problem with this?
for i,j in en:
  print (f"{i} is in position {j}")

l=[ 1, 2, 3]
m=map(str, l)
print(m)
print(list(m))
m=map(lambda x:x*2, l)
print(list(m))