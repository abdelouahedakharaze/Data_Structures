en=enumerate(["a", "b", "c"])
# try them one by one 
print(en)

# ok let's try to print it 
print(list(en))

# what is the problem with this?
for i,j in en:
  print (f"{i} is in position {j}")

