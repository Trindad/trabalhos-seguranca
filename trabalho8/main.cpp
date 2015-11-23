/**
 * Algoritmo do RSA
 *
 * Implementar mecanismo de geração de chaves para a cifra RSA:

	xed = x (mod N)

	Onde e e’ a chave de cifragem e d e’ a chave de decifragem.

	Como xφ(N) = 1 (mod N)  (prova em [1]) segue que xφ(N) + 1 = x (mod N) 
	Como xφ(N) + 1 = x (mod N) e xed = x (mod N), entao φ(N) + 1 = ed


	Aplicando o modulo φ(N) em φ(N) + 1 = ed temos 1 = ed (mod φ(N)) 
	Ou seja e e d são um número e seu inverso multiplicativo modulo φ(N)

	Para calcular pares de números e e d:
	1 - Escolher quaisquer dois números primos p e q e um numero N sendo pq = N
	2 - Calcular φ(N), usando φ(N) = φ(p)φ(q)
	3 - Escolher um número qualquer e que seja coprimo a φ(N)
	4 - Calcular d = e-1 ( mod φ(N) )
 */
#include <calculator.hpp>

int main(int argc, char const *argv[])
{
	BigInteger p, q, n, e,x;
	
	p.read();
	q.read();
	e.read();
	x.read();

	n = Calculator::mult(p,q);// ( p * q ) = n

	/**
	 * Obtendo φ(n) = φ(p)φ(q) = (p − 1)(q − 1) 
	 * Euler's phi function
	 */
	BigInteger t(1);

	BigInteger p1 = Calculator::sub(p,t);
	BigInteger q1 = Calculator::sub(q,t); 

	BigInteger phi = Calculator::mult(p1,q1);

	/**
	 * Obtêm número e que é um número coprimo
	 */
	BigInteger coprimo = Calculator::gcd(BigInteger(1),n);

	cout<<"coprimo =  "<<coprimo.toString()<<endl;
	/**
	 * Calcular d = e-1 (mod φ(n))
	 */
	BigInteger d = Calculator::inverse(e,phi);

	/**
	 * Resultado: x^ed = x (mod N)
	 */
	BigInteger r= Calculator::pow(x,Calculator::mult(e,d),n);

	cout<<"n = "<<n.toString()<<" d = "<<d.toString()<<" e = "<<e.toString()<<" "<<r.toString()<<endl;

	return 0;
}