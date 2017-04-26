package com.example.ioandinu.test.database;

import java.util.ArrayList;
import java.util.List;

import io.realm.RealmObject;
import io.realm.annotations.PrimaryKey;


public class ItemsToGuess extends RealmObject{
    @PrimaryKey
    private int id ;
    private String textToGuess;
    private boolean isGuessed = false;
    private int drawable;
    private String hintDescription;
    private String hintChars;

    public String getHintDescription() {
        return hintDescription;
    }

    public void setHintDescription(String hintDescription) {
        this.hintDescription = hintDescription;
    }

    public String getHintChars() {
        return hintChars;
    }

    public void setHintChars(String hintChars) {
        this.hintChars = hintChars;
    }

    public boolean isGuessed() {
        return isGuessed;
    }

    public void setGuessed(boolean guessed) {
        isGuessed = guessed;
    }

    public ItemsToGuess(){
        this.textToGuess = "";
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getTextToGuess() {
        return textToGuess;
    }

    public void setTextToGuess(String textToGuess) {
        this.textToGuess = textToGuess;
    }

    public int getDrawable() {
        return drawable;
    }

    public void setDrawable(int drawable) {
        this.drawable = drawable;
    }
}
