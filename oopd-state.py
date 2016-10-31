#!/usr/bin/python3

class Person(object):
	"""docstring for Person"""
	def __init__(self):
		super(Person, self).__init__()
		self.marital_state = MaritalState().single()

	def marry(self):
		self.marital_state = self.marital_state.marry()

	def divorce(self):
		self.marital_state = self.marital_state.divorce()

	def widow(self):
		self.marital_state = self.marital_state.widow()

	def print_marital_state(self):
		print(self.marital_state)

class MaritalState(object):
	def __init__(self):
		pass

	def single(self):
		return Single()

	def marry(self):
		return Married()

	def divorce(self):
		return Divorced()

	def widow(self):
		return Widowed()

	def __str__(self):
		raise NotImplementedError

class Single(MaritalState):
	def divorce(self):
		return self

	def widow(self):
		return self

	def __str__(self):
		return 'Single'

class Married(MaritalState):
	def single(self):
		return self

	def __str__(self):
		return 'Married'

class Divorced(MaritalState):
	def single(self):
		return self

	def __str__(self):
		return 'Divorced'

class Widowed(MaritalState):
	def single(self):
		return self

	def divorce(self):
		return self

	def __str__(self):
		return 'Widowed'

person = Person()

person.print_marital_state()
person.marry()
person.print_marital_state()
person.divorce()
person.print_marital_state()
person.marry()
person.print_marital_state()
person.widow()
person.print_marital_state()
person.divorce()
person.print_marital_state()
person.marry()
person.print_marital_state()