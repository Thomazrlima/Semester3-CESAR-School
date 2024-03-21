package br.edu.cesarschool.cc.poo.figurageometrica;

class Circulo extends Elipse{

    Circulo(double raio) {
        super("OBJETO CIRCULAR", raio, raio);
    }
    double getRaio(){
        return super.getRaioMaior();
    }
}