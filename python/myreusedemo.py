
import re



#Match对象是一次匹配的结果，包含了很多关于此次匹配的信息，可以使用Match提供的可读属性或方法来获取这些信息。

#属性：
#string: 匹配时使用的文本。
#re: 匹配时使用的Pattern对象。
#pos: 文本中正则表达式开始搜索的索引。值与Pattern.match()和Pattern.seach()方法的同名参数相同。
#endpos: 文本中正则表达式结束搜索的索引。值与Pattern.match()和Pattern.seach()方法的同名参数相同。
#lastindex: 最后一个被捕获的分组在文本中的索引。如果没有被捕获的分组，将为None。
#lastgroup: 最后一个被捕获的分组的别名。如果这个分组没有别名或者没有被捕获的分组，将为None。
#方法：
#
#group([group1, …]): 
#获得一个或多个分组截获的字符串；指定多个参数时将以元组形式返回。group1可以使用编号也可以使用别名；编号0代表整个匹配的子串；不填写参数时，返回group(0)；没有截获字符串的组返回None；截获了多次的组返回最后一次截获的子串。
#groups([default]): 
#以元组形式返回全部分组截获的字符串。相当于调用group(1,2,…last)。default表示没有截获字符串的组以这个值替代，默认为None。
#groupdict([default]): 
#返回以有别名的组的别名为键、以该组截获的子串为值的字典，没有别名的组不包含在内。default含义同上。
#start([group]): 
#返回指定的组截获的子串在string中的起始索引（子串第一个字符的索引）。group默认值为0。
#end([group]): 
#返回指定的组截获的子串在string中的结束索引（子串最后一个字符的索引+1）。group默认值为0。
#span([group]): 
#返回(start(group), end(group))。
#expand(template): 
#将匹配到的分组代入template中然后返回。template中可以使用\id或\g<id>、\g<name>引用分组，但不能使用编号0。\id与\g<id>是等价的；但\10将被认为是第10个分组，如果你想表达\1之后是字符'0'，只能使用\g<1>0。
print('-----------match attribute----------- ')
m = re.match(r'(\w+) (\w+)(?P<sign>.*)', 'hello world!')
 
print ("m.string:", m.string)
print ("m.re:", m.re)
print ("m.pos:", m.pos)
print ("m.endpos:", m.endpos)
print ("m.lastindex:", m.lastindex)
print ("m.lastgroup:", m.lastgroup)

print ("m.group(1,2):", m.group(1, 2))
print ("m.groups():", m.groups())
print ("m.groupdict():", m.groupdict())
print ("m.start(2):", m.start(2))
print ("m.end(2):", m.end(2))
print ("m.span(2):", m.span(2))
print (r"m.expand(r'\2 \1\3'):", m.expand(r'\2 \1\3'))


print('-----------match----------- ')
#match(string[, pos[, endpos]]) | re.match(pattern, string[, flags]): 
#这个方法将从string的pos下标处起尝试匹配pattern；如果pattern结束时仍可匹配，则返回一个Match对象；如果匹配过程中pattern无法匹配，或者匹配未结束就已到达endpos，则返回None。 
#pos和endpos的默认值分别为0和len(string)；re.match()无法指定这两个参数，参数flags用于编译pattern时指定匹配模式。 
#注意：这个方法并不是完全匹配。当pattern结束时若string还有剩余字符，仍然视为成功。想要完全匹配，可以在表达式末尾加上边界匹配符'$'。 

# 将正则表达式编译成Pattern对象
pattern = re.compile(r'hello')
 
# 使用Pattern匹配文本，获得匹配结果，无法匹配时将返回None
match = pattern.match('hello world hello w!')
 
if match:
    # 使用Match获得分组信息
    print (match.group())

#search(string[, pos[, endpos]]) | re.search(pattern, string[, flags]): 
#这个方法用于查找字符串中可以匹配成功的子串。从string的pos下标处起尝试匹配pattern，如果pattern结束时仍可匹配，则返回一个Match对象；
#若无法匹配，则将pos加1后重新尝试匹配；直到pos=endpos时仍无法匹配则返回None。 
#pos和endpos的默认值分别为0和len(string))；re.search()无法指定这两个参数，参数flags用于编译pattern时指定匹配模式。 
# 将正则表达式编译成Pattern对象 
print('-----------search----------- ')
pattern = re.compile(r'world') 
# 使用search()查找匹配的子串，不存在能匹配的子串时将返回None 
# 这个例子中使用match()无法成功匹配 
match = pattern.search('hello world!') 
 
if match: 
    # 使用Match获得分组信息 
    print (match.group()) 
	
print('-----------split----------- ')
#split(string[, maxsplit]) | re.split(pattern, string[, maxsplit]): 
#按照能够匹配的子串将string分割后返回列表。maxsplit用于指定最大分割次数，不指定将全部分割。 
p = re.compile(r'\d+')
print (p.split('one1111two2three3four4'))

print('-----------findall----------- ')
#findall(string[, pos[, endpos]]) | re.findall(pattern, string[, flags]): 
#搜索string，以列表形式返回全部能匹配的子串。
p = re.compile(r'\d+')
print (p.findall('one1two2three3four4'))

print('-----------finditer----------- ')
#finditer(string[, pos[, endpos]]) | re.finditer(pattern, string[, flags]): 
#搜索string，返回一个顺序访问每一个匹配结果（Match对象）的迭代器。 
p = re.compile(r'\d+')
for m in p.finditer('one1two2three3four4'):
    print (m.group())
	
print('-----------sub----------- ')
p = re.compile(r'(\w+) (\w+)')
s = 'i say a, hello world!'
 
print (p.sub(r'\2 \1', s))
 
def func(m):
    return m.group(1).title() + ' ' + m.group(2).title()
 
print (p.sub(func, s))

# (?<=...)
print("---------(?<=...)-------------")
m = re.search('(?<=abc)def', 'abcdef')
print(m.group(0))
m = re.search('(?<=-)\w+', 'spam-egg')
print(m.group(0))


line = "Cats are smarter than dogs"
 
matchObj = re.match( r'(.*) are (.*?) .*', line, re.M|re.I)
 
if matchObj:
   print ("matchObj.group() : ", matchObj.group())
   print ("matchObj.group(1) : ", matchObj.group(1))
   print ("matchObj.group(2) : ", matchObj.group(2))
   print ("matchObj.groups : ", matchObj.groups())
else:
   print ("No match!!")
