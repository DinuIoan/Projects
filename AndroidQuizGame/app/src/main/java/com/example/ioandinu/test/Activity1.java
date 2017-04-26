/*
 * Copyright (C) 2012 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package com.example.ioandinu.test;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;

import com.example.ioandinu.test.database.ItemsToGuess;
import com.example.ioandinu.test.database.Level2;
import com.facebook.stetho.Stetho;
import com.uphyca.stetho_realm.RealmInspectorModulesProvider;

import java.util.ArrayList;
import java.util.List;
import java.util.logging.Level;

import io.realm.Realm;
import io.realm.RealmConfiguration;
import io.realm.RealmQuery;


/**
 * Example Activity to demonstrate the lifecycle callback methods.
 */
public class Activity1 extends Activity {
   // private RealmConfiguration database ;
   private Realm realm;



    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_1);

        Stetho.initialize(
                Stetho.newInitializerBuilder(this)
                        .enableDumpapp(Stetho.defaultDumperPluginsProvider(this))
                        .enableWebKitInspector(RealmInspectorModulesProvider.builder(this).build())
                        .build());



        //realm = Realm.getInstance(this);

        RealmConfiguration realmConfiguration = new RealmConfiguration.Builder(this)
                .name(Realm.DEFAULT_REALM_NAME)
                .schemaVersion(0)
                .deleteRealmIfMigrationNeeded()
                .build();
        Realm.setDefaultConfiguration(realmConfiguration);

        realm = Realm.getDefaultInstance();


        RealmQuery<ItemsToGuess> query = realm.where(ItemsToGuess.class);
        long numberOfEntries = query.count();

        List<String> names = new ArrayList<>();
        names.add(0,"Infinity");
        names.add(1,"Mercedes");
        names.add(2,"Toyota");
        names.add(3,"Mitsubishi");
        names.add(4,"Mazda");
        names.add(5,"Jaguar");
        names.add(6,"Chevrolet");
        names.add(7,"Dodge");
        names.add(8,"Cadillac");
        names.add(9,"Audi");
        names.add(10,"Volvo");
        names.add(11,"Opel");
        names.add(12,"Honda");
        names.add(13,"Porsche");
        names.add(14,"Renault");
        names.add(15,"Subaru");
        names.add(16,"Pontiac");
        names.add(17,"Lamborghini");
        names.add(18,"Peugeot");
        names.add(19,"Lexus");
        names.add(20,"Maserati");
        names.add(21,"BMW");
        names.add(22,"Suzuki");
        names.add(23,"Fiat");
        names.add(24,"Seat");
        names.add(25,"Nissan");
        names.add(26,"Bentley");
        names.add(27,"Buick");
        names.add(28,"Saab");
        names.add(29,"Daewoo");
        names.add(30,"Saturn");
        names.add(31,"Holden");
        names.add(32,"Vauxhall");
        names.add(33,"Acura");
        names.add(34,"Corvette");
        names.add(35,"Saleen");
        names.add(36,"Land Rover");
        names.add(37,"Mustang");
        names.add(38,"Koenigsegg");
        names.add(39,"Lotus");
        names.add(40,"Lincoln");
        names.add(41,"Hummer");
        names.add(42,"Maybach");
        names.add(43,"Ssangyong");
        names.add(44,"GMC");
        names.add(45,"Dacia");
        names.add(46,"Smart");
        names.add(47,"Bugatti");
        names.add(48,"Aston Martin");

        List<Integer> drawables = new ArrayList<>();
        drawables.add(R.drawable.a1);
        drawables.add(R.drawable.a2);
        drawables.add(R.drawable.a3);
        drawables.add(R.drawable.a4);
        drawables.add(R.drawable.a5);
        drawables.add(R.drawable.a6);
        drawables.add(R.drawable.a7);
        drawables.add(R.drawable.a8);
        drawables.add(R.drawable.a9);
        drawables.add(R.drawable.a10);
        drawables.add(R.drawable.a11);
        drawables.add(R.drawable.a12);
        drawables.add(R.drawable.a13);
        drawables.add(R.drawable.a14);
        drawables.add(R.drawable.a15);
        drawables.add(R.drawable.a16);
        drawables.add(R.drawable.a17);
        drawables.add(R.drawable.a18);
        drawables.add(R.drawable.a19);
        drawables.add(R.drawable.a20);
        drawables.add(R.drawable.a21);
        drawables.add(R.drawable.a22);
        drawables.add(R.drawable.a23);
        drawables.add(R.drawable.a24);
        drawables.add(R.drawable.a25);
        drawables.add(R.drawable.a26);
        drawables.add(R.drawable.a27);
        drawables.add(R.drawable.a28);
        drawables.add(R.drawable.a29);
        drawables.add(R.drawable.a30);
        drawables.add(R.drawable.a31);
        drawables.add(R.drawable.a32);
        drawables.add(R.drawable.a33);
        drawables.add(R.drawable.a34);
        drawables.add(R.drawable.a35);
        drawables.add(R.drawable.a36);
        drawables.add(R.drawable.a37);
        drawables.add(R.drawable.a38);
        drawables.add(R.drawable.a39);
        drawables.add(R.drawable.a40);
        drawables.add(R.drawable.a41);
        drawables.add(R.drawable.a42);
        drawables.add(R.drawable.a43);
        drawables.add(R.drawable.a44);
        drawables.add(R.drawable.a45);
        drawables.add(R.drawable.a46);
        drawables.add(R.drawable.a48);
        drawables.add(R.drawable.a49);
        drawables.add(R.drawable.a50);

        List<String> hints = new ArrayList<>();
        hints.add("Is the luxury vehicle division of Japanese automaker Nissan");
        hints.add("Is a global automobile manufacturer and a division of the German company Daimler AG. The brand is known for luxury vehicles, buses, coaches, and trucks.");
        hints.add("Is a Japanese automotive manufacturer headquartered in the city with the same name of the automotive manufacturer.");
        hints.add("Is a group of autonomous Japanese multinational companies in a variety of industries which was disbanded during the occupation of Japan following World War II.");
        hints.add("Is a Japanese automaker and it's name means wisdom.");
        hints.add("Is the luxury vehicle brand of _____ Land Rover owned by the Indian company Tata Motors since 2008.");
        hints.add("Is an American automobile division of the American manufacturer General Motors colloquially referred to as Chevy.");
        hints.add("Is an American brand of cars, minivans, and sport utility vehicles manufactured by Chrysler Group LLC.");
        hints.add("Is among the oldest automobile brands in the world, second in America only to fellow GM marque Buick.");
        hints.add("The company name is based on the Latin translation of the surname of the founder, August Horch. Horch, meaning listen in German, becomes ____ in Latin.");
        hints.add("Is a Swedish multinational manufacturing company which also supplies marine and industrial drive systems and financial services.");
        hints.add("The company began manufacturing bicycles in 1886 and produced its first automobile in 1899.");
        hints.add("Is a Japanese public mutinational conglomerate corporation primarily known as a manufacturer of automobiles, motorcycles and power equipment.");
        hints.add("Is a German automobile manufacturer specializing in high-performance sports cars, SUVs and sedans.");
        hints.add("Is known for its role in motor sport, particularly rallying, Formula 1 and Formula E. Its early work on mathematical curve modeling for car bodies is important in the history of computer graphics.");
        hints.add("Is the Japanese name for the Pleiades star cluster M45, or "+ "The Seven Sisters");
        hints.add("Was a brand of automobiles manufactured and sold by General Motors (GM),though production ended in 2009, ____ remains a registered and active trademark of GM.");
        hints.add("Is an Italian brand and manufacturer of luxury sports cars and SUVs which is owned by the Volkswagen Group through its subsidiary Audi.");
        hints.add("The family business that preceded the current _____ company was founded in 1810, and manufactured coffee mills and bicycles.");
        hints.add("Is the luxury vehicle division of Japanese automaker Toyota.");
        hints.add("The ______ tagline is" + "Luxury, sports and style cast in exclusive cars" + ", and the brand's mission statement is to " + "Build ultra-luxury performance automobiles with timeless Italian style, accommodating bespoke interiors, and effortless, signature sounding power");
        hints.add("First this company started as a aircraft engine manufacturer.");
        hints.add("The company's first 30 years focused on the development and production of weaving machines.");
        hints.add("Is the smallest automobile manufacturer in Uzbekistan.");
        hints.add("Is a Spanish automobile manufacturer with its head office in Martorell, Spain.");
        hints.add("_____ Motor sells its cars under the _____, Infiniti, and Datsun brands with in-house performance tuning products labelled Nismo.");
        hints.add("_____ won the 24 Hours of Le Mans in 1924, 1927, 1928, 1929, 1930, and 2003.");
        hints.add("Has been marketed as a premium automobile brand, selling luxury vehicles positioned above GM's mainstream brands, e.g. Chevrolet, while below the flagship luxury Cadillac division.");
        hints.add("A Swedish automobile manufacturer.");
        hints.add("It was founded on 22 March 1967 and was dismantled by the Korean government in 1999.");
        hints.add("General Motors discontinued the ____ brand and ended its outstanding franchises on October 31, 2010");
        hints.add("Is an Australian automobile manufacturer that operates in Australasia and is headquartered in Port Melbourne, Victoria.");
        hints.add("The company sells passenger cars and light commercial vehicles under the _____ marque; in the past it has also sold buses and trucks under the Bedford brand.");
        hints.add("Is the luxury vehicle marque of Japanese automaker Honda.");
        hints.add("Known colloquially as the Vette, is a sports car manufactured by Chevrolet.");
        hints.add("Is an American manufacturer of specialty high-performance sports cars and high-performance automotive parts headquartered in Corona, California.");
        hints.add("It is owned by India's Tata Motors since 2008.");
        hints.add("Is an American automobile manufactured by Ford");
        hints.add("Is a Swedish manufacturer of high-performance sports cars, based in Ängelholm, Skåne County, Sweden.");
        hints.add("Is a British manufacturer of sports and racing cars, famous for its Esprit, Elan, Europa and Elise sports cars and for the highly successful Team Lotus in Formula One.");
        hints.add("The current _____ model range in North America consists of two sedans (MKS and MKZ), three crossover utility vehicles (MKC, MKT, and MKX), and two sport utility vehicles (Navigator/Navigator L).");
        hints.add("Was a brand of trucks and SUVs, first marketed in 1992 when AM General began selling a civilian version of the M998 Humvee.");
        hints.add("Was a German car manufacturer which ended it's activity in 2013.");
        hints.add("Is a South Korean based Chaebol or conglomerate. _____, literally translated, means " + "Double Dragon");
        hints.add("Is a division of the American automobile manufacturer General Motors (GM) that primarily focuses on trucks and utility vehicles. ____ sells pickup and commercial trucks, buses, vans, military vehicles, and sport utility vehicles marketed worldwide by General Motors.");
        hints.add("Is a Romanian car manufacturer that takes its name from the historic region that constitutes much of present-day Romania.");
        hints.add("The brand name _____ derives from its early cooperative studies with Swatch and Mercedes.");
        hints.add("Is a company that builds limited production exclusive sports cars.");
        hints.add("Is a British manufacturer of luxury sports cars and grand tourers. It was founded in 1913 by Lionel Martin and Robert Bamford.");


        List<String> hints2 = new ArrayList<>();
        hints2.add("I--i---y");
        hints2.add("M------s");
        hints2.add("T---t-");
        hints2.add("M--s----h-");
        hints2.add("M--d-");
        hints2.add("J---a-");
        hints2.add("C--v----t");
        hints2.add("D--g-");
        hints2.add("D--g-");
        hints2.add("C---ll--");
        hints2.add("A-d-");
        hints2.add("V--v-");
        hints2.add("O--l");
        hints2.add("H-n--");
        hints2.add("P---c--");
        hints2.add("R----l-");
        hints2.add("S--a--");
        hints2.add("P-n---c");
        hints2.add("L--b---h---");
        hints2.add("P-u----");
        hints2.add("L-x--");
        hints2.add("M---r--i");
        hints2.add("B--");
        hints2.add("S----i");
        hints2.add("F---");
        hints2.add("S---");
        hints2.add("N--s--");
        hints2.add("B--t---");
        hints2.add("B----");
        hints2.add("S---");
        hints2.add("D--w--");
        hints2.add("S---r-");
        hints2.add("H--d--");
        hints2.add("V-u-----");
        hints2.add("A-u--");
        hints2.add("C----t--");
        hints2.add("S---e-");
        hints2.add("-A-- --V--");
        hints2.add("--s--n-");
        hints2.add("--e--g---g");
        hints2.add("-o--s");
        hints2.add("-i---l-");
        hints2.add("--mm--");
        hints2.add("-s---y---");
        hints2.add("-M-");
        hints2.add("-a--a");
        hints2.add("-m-r-");
        hints2.add("--g--t-");
        hints2.add("-s--- --r--n");




        Bundle bundle = getIntent().getExtras();

        List<String> names2 = new ArrayList<>();
        List<Integer> drawables2 = new ArrayList<>();
        names2.add("Seat");
        names2.add("Mercedes");
        names2.add("Aston Martin");
        names2.add("Volvo");
        names2.add("BMW");
        names2.add("Chevrolet");
        names2.add("Volkswagen");
        names2.add("Dacia");
        names2.add("Tesla");
        names2.add("Mustang");
        names2.add("BMW");
        names2.add("Bugatti");
        names2.add("Honda");
        names2.add("Bentley");
        names2.add("Chevrolet");
        names2.add("Audi");
        names2.add("Corvette");
        names2.add("Hyundai");
        names2.add("Lexus");
        names2.add("Mini Cooper");
        names2.add("Ferrari");
        names2.add("Lotus");
        names2.add("Alfa Romeo");
        names2.add("Ferrari");
        names2.add("Fiat");
        names2.add("Ford");
        names2.add("Mazda");
        names2.add("Hummer");
        names2.add("Daewoo");
        names2.add("Nissan");
        names2.add("Opel");
        names2.add("Peugeot");
        names2.add("Lamborghini");
        names2.add("Nissan");
        names2.add("Porsche");
        names2.add("Skoda");
        names2.add("Volkswagen");
        names2.add("Mercedes");
        names2.add("Renault");
        names2.add("Land Rover");
        names2.add("Opel");
        names2.add("Suzuki");
        names2.add("Cadillac");
        names2.add("Jaguar");
        names2.add("Maserati");
        names2.add("Smart");
        names2.add("Toyota");
        names2.add("Nissan");
        names2.add("Nissan");

        drawables2.add(R.drawable.b1);
        drawables2.add(R.drawable.b2);
        drawables2.add(R.drawable.b3);
        drawables2.add(R.drawable.b4);
        drawables2.add(R.drawable.b5);
        drawables2.add(R.drawable.b6);
        drawables2.add(R.drawable.b7);
        drawables2.add(R.drawable.b8);
        drawables2.add(R.drawable.b9);
        drawables2.add(R.drawable.b10);
        drawables2.add(R.drawable.b11);
        drawables2.add(R.drawable.b12);
        drawables2.add(R.drawable.b13);
        drawables2.add(R.drawable.b14);
        drawables2.add(R.drawable.b15);
        drawables2.add(R.drawable.b16);
        drawables2.add(R.drawable.b17);
        drawables2.add(R.drawable.b18);
        drawables2.add(R.drawable.b19);
        drawables2.add(R.drawable.b20);
        drawables2.add(R.drawable.b21);
        drawables2.add(R.drawable.b22);
        drawables2.add(R.drawable.b23);
        drawables2.add(R.drawable.b24);
        drawables2.add(R.drawable.b25);
        drawables2.add(R.drawable.b26);
        drawables2.add(R.drawable.b27);
        drawables2.add(R.drawable.b28);
        drawables2.add(R.drawable.b29);
        drawables2.add(R.drawable.b30);
        drawables2.add(R.drawable.b31);
        drawables2.add(R.drawable.b32);
        drawables2.add(R.drawable.b33);
        drawables2.add(R.drawable.b34);
        drawables2.add(R.drawable.b35);
        drawables2.add(R.drawable.b36);
        drawables2.add(R.drawable.b37);
        drawables2.add(R.drawable.b38);
        drawables2.add(R.drawable.b39);
        drawables2.add(R.drawable.b40);
        drawables2.add(R.drawable.b41);
        drawables2.add(R.drawable.b42);
        drawables2.add(R.drawable.b43);
        drawables2.add(R.drawable.b44);
        drawables2.add(R.drawable.b45);
        drawables2.add(R.drawable.b46);
        drawables2.add(R.drawable.b47);
        drawables2.add(R.drawable.b48);
        drawables2.add(R.drawable.b49);

        if(numberOfEntries < 49) {
            for (int i = 0; i < 49; i++) {
//                Bitmap icon = BitmapFactory.decodeResource(this.getResources(),
//                        drawables.get(i));
//                ByteArrayOutputStream stream = new ByteArrayOutputStream();
//                icon.compress(Bitmap.CompressFormat.PNG, 100, stream);
//                byte[] byteArray = stream.toByteArray();



                ItemsToGuess itemsToGuess = new ItemsToGuess();
                itemsToGuess.setTextToGuess(names.get(i));
                itemsToGuess.setGuessed(false);
                itemsToGuess.setId(i);
                itemsToGuess.setDrawable(drawables.get(i));
                itemsToGuess.setHintChars(hints2.get(i));
                itemsToGuess.setHintDescription(hints.get(i));

                Level2 level2 = new Level2();
                level2.setTextToGuess(names2.get(i));
                level2.setGuessed(false);
                level2.setId(i);
                level2.setDrawable(drawables2.get(i));
                level2.setHintChars(hints2.get(i));
                level2.setHintDescription(hints.get(i));

                realm.beginTransaction();
                itemsToGuess = realm.copyToRealm(itemsToGuess);
                level2 = realm.copyToRealm(level2);
                realm.commitTransaction();
            }


        }



//        ItemsToGuess itemsToGuess = new ItemsToGuess();
//        itemsToGuess.setTextToGuess("Infinity");
//        itemsToGuess.setId(1);
//        itemsToGuess.setGuessed(false);
//
//        realm.beginTransaction();
//        itemsToGuess = realm.copyToRealm(itemsToGuess);
//        realm.commitTransaction();




//        Stetho.initialize(
//                Stetho.newInitializerBuilder(this)
//                        .enableDumpapp(Stetho.defaultDumperPluginsProvider(this))
//                        .enableWebKitInspector(RealmInspectorModulesProvider.builder(this).build())
//                        .build());





//        database =  new RealmConfiguration.Builder(this)
//                        .name("GuessTheCar.realm")
//                        .deleteRealmIfMigrationNeeded()
//                        .build();
//        Realm.setDefaultConfiguration(database);
//
//        this.realm = RealmController.with(this).getRealm();
//        //RealmController.with(this).refresh();
//       // RealmController.with(this).add("Infinity");
//        //RealmController.with(this).add("Mercedes");
//      //  RealmController.with(this).add("Mazda");
//
//        realm.beginTransaction();
//        ItemsToGuess itemsToGuess1 = realm.createObject(ItemsToGuess.class);
//        itemsToGuess1.setTextToGuess("Infinity");
//        int nextID = (int) (realm.where(ItemsToGuess.class).max("id").intValue() + 1);
//        itemsToGuess1.setId(nextID);
//        itemsToGuess1.setGuessed(false);
//        realm.commitTransaction();
//
//
//       /* ItemsToGuess itemsToGuess2 = realm.createObject(ItemsToGuess.class);
//        itemsToGuess2.setTextToGuess("Mercedes");
//        itemsToGuess2.setId(2);
//        itemsToGuess2.setGuessed(false);
//
//
//
//        ItemsToGuess itemsToGuess3 = realm.createObject(ItemsToGuess.class);
//        itemsToGuess3.setTextToGuess("Mazda");
//        itemsToGuess3.setId(3);
//        itemsToGuess3.setGuessed(false);*/
//        realm.commitTransaction();

    }

    @Override
    protected void onStart() {
        super.onStart();
    }

    @Override
    protected void onRestart() {
        super.onRestart();
    }

    @Override
    protected void onResume() {
        super.onResume();
    }

    @Override
    protected void onPause() {
        super.onPause();
    }

    @Override
    protected void onStop() {
        super.onStop();
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
    }

    public void play(View view)
    {
        Intent i = new Intent(this, Activity2.class);
        startActivity(i);
    }



}
