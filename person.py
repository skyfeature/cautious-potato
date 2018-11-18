# definition/self/properties/methods
class Person:

	name = None
	age = None

	def __init__(self, name, age):
		self.name = name
		self.age = age

	def say_name(self):
		print(self.name)

	def say_age(self):
		print(self.age)

	def have_bd(self):
		self.age += 1