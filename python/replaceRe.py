import re
 
# 将正则表达式编译成Pattern对象
#p = re.compile(r'(?P<folder>(\w+/)*)(?P<filename>\w+\.png)')
p = re.compile(r'(?P<filename>\w+\.png)')
 
the_str = """<key>XXXX/duobaojiemian2222_L/duobaojiemian_L/yangpizi.png</key> 
  <key>yangpizi2.png</key> 
  <key>yangpizi3.png</key> """
 
for m in p.finditer(the_str):
  print (m.groupdict())
  
# for m in p.findall(the_str):
  # print (m)
 
print ('-------------------------------')

def f3(m3):
  d = m3.groupdict()
  return 'demo_'+d['filename']

#replaceStr = p.sub('yyy', the_str)
replaceStr = p.sub(f3, the_str)

print (the_str)     #原字符串不变
print (replaceStr)  #替换后的字符串