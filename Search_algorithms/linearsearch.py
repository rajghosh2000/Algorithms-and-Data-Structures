with open('data.txt') as f:
	content = f.read();
content = list(content)
content = list(filter(('\n').__ne__, content))
print(content)