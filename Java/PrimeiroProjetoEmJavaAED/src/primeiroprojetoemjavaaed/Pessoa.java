package primeiroprojetoemjavaaed;

import java.util.ArrayList;

public class Pessoa {
    
    private int id;
    private String nome;
    private int idade;
    private ArrayList <Cachorro> pets;
    
    public Pessoa(int id, String nome, int idade){
        this.id = id;
        this.nome = nome;
        this.idade = idade;
        pets = new ArrayList<>();
    }
    
    public void adota(Cachorro c){
        pets.add(c);
    }
    
    public void exibe(){
        System.out.println("ID: " + id);
        System.out.println("Nome: " + nome);
        System.out.println("Idade: " + idade);
        
        if(pets.isEmpty())
            System.out.println("Nenhum cachorro adotado.");
        else{
            System.out.println("Cachorros adotados:");
        
//        for(int i = 0; i < pets.size(); i++){
//            //Cachorro c = pets.get(i);
//            pets.get(i).exibe();
//        }
            for(Cachorro c : pets){
                c.exibe();
            }
        }
    }
    
    public Cachorro doa(int i){
        return pets.remove(i);
    }
    
    public Cachorro getCachorro(int i){
        return pets.get(i);
    }
    public Cachorro getCachorro(String nome){
        for(Cachorro c : pets){
            if(c.getNome().equals(nome))
                return c;
        }
        return null;
    }
    
    public int getId() {
        return id;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getIdade() {
        return idade;
    }

    public void setIdade(int idade) {
        this.idade = idade;
    }
}
