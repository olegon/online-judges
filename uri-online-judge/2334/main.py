'''
Patinhos
https://www.urionlinejudge.com.br/judge/pt/problems/view/2334
'''

while True:
    n = int(raw_input())
    
    if n == -1:
        break
    else:
        r = max(0, n - 1)
        print(r)
