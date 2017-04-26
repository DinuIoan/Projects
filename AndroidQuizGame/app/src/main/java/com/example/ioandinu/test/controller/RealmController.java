package com.example.ioandinu.test.controller;

import android.app.Activity;
import android.app.Application;
import android.app.Fragment;

import com.example.ioandinu.test.database.ItemsToGuess;

import io.realm.Realm;
import io.realm.RealmResults;

/**
 * Created by Ioan.Dinu on 7/29/2016.
 */
public class RealmController {
    private static RealmController instance;
    private final Realm realm;
    ItemsToGuess itemsToGuess = new ItemsToGuess();;

    public RealmController(Application application) {
        itemsToGuess = new ItemsToGuess();
        this.realm = Realm.getDefaultInstance();
    }

    public static RealmController with(Fragment fragment) {

        if (instance == null) {
            instance = new RealmController(fragment.getActivity().getApplication());
        }
        return instance;
    }

    public static RealmController with(Activity activity) {

        if (instance == null) {
            instance = new RealmController(activity.getApplication());
        }
        return instance;
    }

    public static RealmController with(Application application) {

        if (instance == null) {
            instance = new RealmController(application);
        }
        return instance;
    }

    public static RealmController getInstance() {

        return instance;
    }

    public Realm getRealm() {

        return realm;
    }

    public void refresh() {

        realm.refresh();
    }

    public void clearAll() {

        realm.beginTransaction();
        realm.clear(ItemsToGuess.class);
        realm.commitTransaction();
    }

    public RealmResults<ItemsToGuess> getAllInfoAboutItemsToGuess() {

        return realm.where(ItemsToGuess.class).findAll();
    }

    public ItemsToGuess getItem(int id) {

        return realm.where(ItemsToGuess.class).equalTo("id", id).findFirst();
    }


    public void add(String name){
        itemsToGuess =  new ItemsToGuess();
        itemsToGuess.setTextToGuess(name);
        realm.beginTransaction();
        realm.copyToRealm(itemsToGuess);
        realm.commitTransaction();
    }

}
