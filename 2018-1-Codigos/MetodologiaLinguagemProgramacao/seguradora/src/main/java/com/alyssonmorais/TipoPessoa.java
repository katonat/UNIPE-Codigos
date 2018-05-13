package com.alyssonmorais;

/**
 * 
 * @author ALYSSON
 *
 */

public enum TipoPessoa {
	
	FISICA("Pessoa F�sica"),
	JURIDICA("Pessoa Jur�dica");
	
	private String tipo;
	
	private TipoPessoa(String tipo) {
		this.tipo = tipo;
	}

	public String getTipo() {
		return tipo;
	}

	public void setTipo(String tipo) {
		this.tipo = tipo;
	}
	
	
}
