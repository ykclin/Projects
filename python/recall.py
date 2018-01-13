#装饰函数的参数是被装饰的函数对象，返回原函数对象装饰的实质语句
def deco(func):
	print('before myfun() called.')
	func()
	print('after myfun() called')
	return func
	
def myfunc():
	print('myfunc() called')
	
tmpfun = deco(myfunc)


#tmpfun()
#myfunc()	