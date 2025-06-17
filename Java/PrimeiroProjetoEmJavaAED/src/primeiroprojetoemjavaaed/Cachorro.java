package primeiroprojetoemjavaaed;

import java.util.ArrayList;

public class Cachorro {
    private String nome, raca;
    private int idade;
    private double peso;
    private char porte;
    
    public Cachorro(String nome, String raca, int idade, double peso, char porte){
        this.nome = nome;
        this.raca = raca;
        this.idade = idade;
        this.peso = peso;
        this.porte = porte;
    }
    
    public void exibe(){
        System.out.println("Nome: " + nome);
        System.out.println("Raça: " + raca);
        System.out.println("Idade: " + idade);
        System.out.println("Peso: " + peso);
        System.out.println("Porte: " + porte);
    }
    public void late(int quantidade){
        for(int i = 0; i < quantidade; i++){
            if(porte == 'P')
                System.out.println("au!");
            if(porte == 'M')
                System.out.println("Au!");
            if(porte == 'G')
                System.out.println("AU!");
        }
    }
    
   public String getNome(){
       return nome;
   }
   public String getRaca(){
       return raca;
   }
   public int getIdade(){
       return idade;
   }
   public double getPeso(){
       return peso;
   }
   public char getPorte(){
       return porte;
   }
   
   public void setRaca(String raca){
       this.raca = raca;
   }
   public void setIdade(int idade){
       this.idade = idade;
   }
   public void setPeso(double peso){
       this.peso = peso;
   }
   public void setPorte(char porte){
       this.porte = porte;
   }
}
