#include <graphics.h>
#include <conio.h>
#include <cmath>
#include <stdio.h>

class player1;

class tpijakan {
public:
    int x1, y1, x2, y2;
    
    tpijakan(int posisix, int posisiy) {
        x1 = posisix;
        y1 = posisiy;
        x2 = 250 + posisix;
        y2 = 25 + posisiy;
    }
    
    void draw() {
        setfillstyle(SOLID_FILL, BROWN);
        bar(x1, y1, x2, y2);
    }
};

class tlindung1 {
public:
    int x1, y1, x2, y2;
    
    tlindung1() {
        x1 = 190;
        y1 = 130;
        x2 = 220;
        y2 = 180;
    }
    
    void draw() {
        setfillstyle(SOLID_FILL, RED);
        bar(x1, y1, x2, y2);
    }
};

class tlindung2 {
public:
    int x1, y1, x2, y2;
    
    tlindung2() {
        x1 = 160;
        y1 = 450;
        x2 = 200;
        y2 = 500;
    }
    
    void draw() {
        setfillstyle(SOLID_FILL, RED);
        bar(x1, y1, x2, y2);
    }
};

class tlindung3 {
public:
    int x1, y1, x2, y2;
    
    tlindung3() {
        x1 = 1010;
        y1 = 130;
        x2 = 1040;
        y2 = 180;
    }
    
    void draw() {
        setfillstyle(SOLID_FILL, RED);
        bar(x1, y1, x2, y2);
    }
};

class tlindung4 {
public:
    int x1, y1, x2, y2;
    
    tlindung4() {
        x1 = 1020;
        y1 = 450;
        x2 = 1060;
        y2 = 500;
    }
    
    void draw() {
        setfillstyle(SOLID_FILL, RED);
        bar(x1, y1, x2, y2);
    }
};

class tlindungtengah1 {
public:
    int x1, y1, x2, y2;
    
    tlindungtengah1() {
        x1 = 500;
        y1 = 300;
        x2 = 520;
        y2 = 340;
    }
    
    void draw() {
        setfillstyle(SOLID_FILL, DARKGRAY);
        bar(x1, y1, x2, y2);
    }
};

class tlindungtengah2 {
public:
    int x1, y1, x2, y2;
    
    tlindungtengah2() {
        x1 = 650;
        y1 = 290;
        x2 = 690;
        y2 = 340;
    }
    
    void draw() {
        setfillstyle(SOLID_FILL, DARKGRAY);
        bar(x1, y1, x2, y2);
    }
};

class tanah {
public:
    int x1, y1, x2, y2;
    
    tanah() {
        x1 = 0;
        y1 = 690;
        x2 = 1200;
        y2 = 750;
    }
    
    void draw() {
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        bar(x1, y1, x2, y2);
    }
};

class Musuhutama {
public:
    int count = 0;
    int x, y, r;
    bool kakikirimaju;
    bool jalan = false;
    bool gerak = false;
    int health = 100;
    int peluruXA[5];
    int peluruYA[5];
    int peluruAktifA[5];
    int peluruXB[5];
    int peluruYB[5];
    int peluruAktifB[5];
    bool musuhserangAktif = false;
    bool musuhmenyerang = false;
    bool menyerang = false;
    bool seranganmusuhkena = false;
    bool nyeranglagi;
    int cooldownattack;
    static const int attackCooldown = 30;
    int spriteWidth = 128;
    int spriteHeight = 128;
    bool menghadapkanan = true ;

    int hitboxWidth ;
    int hitboxoffsetX ;
    
    Musuhutama(int posisix, int posisiy) {
        x = posisix;
        y = posisiy;
        nyeranglagi = true;
        cooldownattack = 0;
        hitboxWidth = 40; 
        
    }
    
    void bar_darah() {
        int lebar = 220;
        int tinggi = 16;
        int lebar_darah = (health * lebar) / 100;
        
        setfillstyle(SOLID_FILL, BLACK);
        bar(931, 51, 1149, 65);
        
        setfillstyle(SOLID_FILL, RED);
        bar(931, 51, 931 + lebar_darah, 65);
    }
    
    void draw() {
        setcolor(WHITE);
        circle(x, y, 20); 
        line(x, y + 20, x, y + 80);
        
        if (menyerang) {
            if (menghadapkanan) { 
                tangankananmusuh(true);
                tangankirimusuh(false);
            } else { 
                tangankananmusuh(false);
                tangankirimusuh(true);
            }
        } else { 
            tangankananmusuh(false);
            tangankirimusuh(false);
        }
        
        if (jalan == false) {
            line(x, y + 80, x - 15, y + 120);
            line(x, y + 80, x + 15, y + 120);
        }
        
        if (jalan) {
            count++;
            if (count == 1) {
                line(x, y + 80, x - 20, y + 120);
                line(x, y + 80, x + 10, y + 120);
            }
            if (count == 2) {
                line(x, y + 80, x - 10, y + 120);
                line(x, y + 80, x + 20, y + 120);
            }
            if (count >= 2) {
                count = 0;
            }
        }
    }
    
    void tangankananmusuh(bool serangan, bool hapus = false) {
        int panjangtangan = 30;
        int jarakserang = 10;
        int tanganX = x + panjangtangan;
        int tanganY = y + 60;
        
        if (serangan) {
            tanganX += jarakserang;
            line(x, y + 40, tanganX, tanganY);
            circle(tanganX, tanganY, 10);
            
            
        } else{
            line(x, y + 40, tanganX, tanganY);
            circle(tanganX, tanganY, 5);
        }
        setcolor(WHITE);
    }
    
    void tangankirimusuh(bool serangan, bool hapus = false) {
        int panjangtangan = 30;
        int jarakserang = 10;
        int tanganX = x - panjangtangan;
        int tanganY = y + 60;
        
        if (serangan) {
            tanganX -= jarakserang;
            line(x, y + 40, tanganX, tanganY);
            circle(tanganX, tanganY, 10);
        } else{
            line(x, y + 40, tanganX, tanganY);
            circle(tanganX, tanganY, 5);
        }
        setcolor(WHITE);
       
    }
    
    void gerakkanan(int player1X) {
        menghadapkanan = true;
        musuhmenyerang = true;
        int jarak = abs(player1X - x);
        if (jarak > 30) {
            x += 5;
            jalan = true;
            menyerang = false;
        } else {
            jalan = false;
            menyerang = true;
        }
        if (x > 1200) {
            x = 0;
        }
    }
    
    bool diatastanah() {
        return y == 570;
    }
    
    void gerakkiri(int player1X) {
        menghadapkanan = false;
        int jarak = abs(player1X - x);
        if (jarak > 30) {
            x -= 5;
            jalan = true;
            menyerang = false;
        } else {
            jalan = false;
            menyerang = true;
        }
        musuhmenyerang = false;
        if (x < 0) {
            x = 1200;
        }
    }
    
    void naik() {
        if (y > 0 + 20) {
            y -= 10;
        }
        jalan = true;
    }
    
    void turun() {
        y += 10;
        if (y > 570) {
            y = 570;
        }
        jalan = true;
    }
    
    void gerakmusuh(int player1X) {
        if (this->x < player1X) {
        
        gerakkanan(player1X);
    } else if (this->x > player1X) {
      
        gerakkiri(player1X);
    }
    }

    void updateSerangan(player1& p1);
};

class player1 {
public:
    int count = 0;
    int x, y, r;
    bool kakikirimaju;
    bool jalan = false;
    int health = 100;
    int cek_y;
    int peluruX[5];
    int peluruY[5];
    int peluruAktif[5];
    int peluruX1[5];
    int peluruY1[5];
    int peluruAktif1[5];
    bool serangkanan = false;
    bool serangkiri = false;
    bool menghadapkanan = true;
    int modeserang;
    
    void* spritejalan_kanan[10];
    void* spritejalanmasking_kanan[10];
    void* spritejalan_kiri[10];
    void* spritejalanmasking_kiri[10];
    
    void* spritesamuraikanan[8];
    void* spritesamuraimaskingkanan[8];
    void* spritesamuraikiri[8];
    void* spritesamuraimaskingkiri[8];
    
    void* spritesamuraiserangkanan[5];
    void* spritesamuraiserangmaskingkanan[5];
    void* spritesamuraiserangkiri[5];
    void* spritesamuraiserangmaskingkiri[5];
    
    int animcounter = 0;
    int indexframe = 0;
    bool isAttacking = false;
    int attackFrameIndex = 0;
    int attackAnimCounter = 0;
    
    bool pakesrpite = false;
    int spriteWidth = 128;
    int spriteHeight = 128;

    bool suarapedang;
    bool suaralari;
    
    void bar_darah() {
        int lebar = 220;
        int lebar_darah = (health * lebar) / 100;
        
        setfillstyle(SOLID_FILL, BLACK);
        bar(51, 51, 51 + lebar, 65);
        
        setfillstyle(SOLID_FILL, RED);
        if (health > 0) {
            bar(51, 51, 51 + lebar_darah, 65);
        }
    }
    
    player1(int posisix, int posisiy) {
        x = posisix;
        y = posisiy;
        cek_y = posisiy;
        modeserang = 2;
        for (int i = 0; i < 5; i++) {
            peluruAktif[i] = 0;
        }
        for (int a = 0; a < 5; a++) {
            peluruAktif1[a] = 0;
        }
        suaralari = false;
    }
    
    void load_animasi_sprite(const char* namafile, const char* namafilemasking, void* sprite_array[], void* masking_array[], int jumlahFrame, int lebarFrame, int tinggiFrame) {
        readimagefile(namafilemasking, 0, 0, jumlahFrame * lebarFrame, tinggiFrame);
        for (int i = 0; i < jumlahFrame; i++) {
            int left = i * lebarFrame;
            int top = 0;
            int right = (i + 1) * lebarFrame - 1;
            int bottom = tinggiFrame - 1;
            masking_array[i] = malloc(imagesize(left, top, right, bottom));
            getimage(left, top, right, bottom, masking_array[i]);
        }
        cleardevice();
        
        readimagefile(namafile, 0, 0, jumlahFrame * lebarFrame, tinggiFrame);
        for (int i = 0; i < jumlahFrame; i++) {
            int left = i * lebarFrame;
            int top = 0;
            int right = (i + 1) * lebarFrame - 1;
            int bottom = tinggiFrame - 1;
            sprite_array[i] = malloc(imagesize(left, top, right, bottom));
            getimage(left, top, right, bottom, sprite_array[i]);
        }
    }
    
    void loadsprites(
        const char* penembak_kanan, const char* penembak_mask_kanan,
        const char* penembak_kiri, const char* penembak_mask_kiri,
        const char* samurai_kanan, const char* samurai_mask_kanan,
        const char* samurai_kiri, const char* samurai_mask_kiri,
        const char* samurai_atk_kanan, const char* samurai_atk_mask_kanan,
        const char* samurai_atk_kiri, const char* samurai_atk_mask_kiri
    ) {
        int currentPage = getactivepage();
        setactivepage(3);
        
        load_animasi_sprite(penembak_kanan, penembak_mask_kanan, spritejalan_kanan, spritejalanmasking_kanan, 10, 128, 128);
        load_animasi_sprite(penembak_kiri, penembak_mask_kiri, spritejalan_kiri, spritejalanmasking_kiri, 10, 128, 128);
        load_animasi_sprite(samurai_kanan, samurai_mask_kanan, spritesamuraikanan, spritesamuraimaskingkanan, 8, 128, 128);
        load_animasi_sprite(samurai_kiri, samurai_mask_kiri, spritesamuraikiri, spritesamuraimaskingkiri, 8, 128, 128);
        
        int serangframecount = 5;
        int serangframeWidth = 128;
        int serangframeHeight = 128;
        load_animasi_sprite(samurai_atk_kanan, samurai_atk_mask_kanan, spritesamuraiserangkanan, spritesamuraiserangmaskingkanan, serangframecount, serangframeWidth, serangframeHeight);
        load_animasi_sprite(samurai_atk_kiri, samurai_atk_mask_kiri, spritesamuraiserangkiri, spritesamuraiserangmaskingkiri, serangframecount, serangframeWidth, serangframeHeight);
        
        setactivepage(currentPage);
    }
    
    void drawsprite() {

        if(isAttacking) {
            attackAnimCounter++;
            if(attackAnimCounter >= 3) {
                attackFrameIndex++;
                attackAnimCounter = 0;
            }
            int maksattackframe;
            if(modeserang == 1) {
                maksattackframe = 5; 
            } else {
                maksattackframe = 4; 
            }
            if(attackFrameIndex >= maksattackframe) {
                isAttacking = false;
                attackFrameIndex = 0;
            }
            int drawX = x-spriteWidth/2;
            int drawY = y-spriteHeight/2;
            if(menghadapkanan) {
                putimage(drawX, drawY, spritesamuraiserangmaskingkanan[attackFrameIndex], AND_PUT);
                putimage(drawX, drawY, spritesamuraiserangkanan[attackFrameIndex], OR_PUT);
            } else {
                putimage(drawX, drawY, spritesamuraiserangmaskingkiri[attackFrameIndex], AND_PUT);
                putimage(drawX, drawY, spritesamuraiserangkiri[attackFrameIndex], OR_PUT);
            }
            return;
        }
        
        if (jalan) {
            animcounter++;
            if (animcounter >= 3) {
            animcounter = 0; 
            int frameCount ;
            if(modeserang == 1) {
                frameCount = 8; 
            } else{
                frameCount = 10; 
            }
            \
            indexframe = (indexframe + 1) % frameCount;
        }
    } else {
        indexframe = 0; 
    }
        
        if(modeserang ==1) {
            if(menghadapkanan) {
                putimage(x,y,spritesamuraimaskingkanan[indexframe], AND_PUT);
                putimage(x,y,spritesamuraikanan[indexframe], OR_PUT);
            } else {
                putimage(x,y,spritesamuraimaskingkiri[indexframe], AND_PUT);
                putimage(x,y,spritesamuraikiri[indexframe], OR_PUT);
            }
        } else if(modeserang == 2) {
            if (menghadapkanan) {
                putimage(x, y, spritejalanmasking_kanan[indexframe], AND_PUT);
                putimage(x, y, spritejalan_kanan[indexframe], OR_PUT);
            } else {
                putimage(x, y, spritejalanmasking_kiri[indexframe], AND_PUT);
                putimage(x, y, spritejalan_kiri[indexframe], OR_PUT);
            }
        }
    }
    
    void draw() {
        if (pakesrpite) {
            drawsprite();
        } else {
            setcolor(WHITE);
            circle(x, y, 20);
            line(x, y + 20, x, y + 80);
            if (jalan == false) {
                line(x, y + 80, x - 15, y + 120);
                line(x, y + 80, x + 15, y + 120);
            }
            if (serangkanan == false) {
                line(x, y + 40, x + 30, y + 60);
                circle(x + 30, y + 60, 15);
            }
            if (serangkiri == false) {
                line(x, y + 40, x - 30, y + 60);
                circle(x - 30, y + 60, 15);
            }
            if (serangkanan == true) {
                line(x, y + 42, x + 42, y + 44);
                circle(x + 42, y + 44, 15);
                serangkanan = false;
            }
            if (serangkiri == true) {
                line(x, y + 42, x - 42, y + 44);
                circle(x - 42, y + 44, 15);
                serangkiri = false;
            }
            if (jalan == true) {
                count++;
                if (count == 1) {
                    line(x, y + 80, x - 20, y + 120);
                    line(x, y + 80, x + 10, y + 120);
                }
                if (count == 2) {
                    line(x, y + 80, x - 10, y + 120);
                    line(x, y + 80, x + 20, y + 120);
                }
                if (count >= 2) {
                    count = 0;
                }
            }
        }
    }
    
    void seranganjarakdekat(Musuhutama& p2) {
        mciSendString("play sfx_serang from 0", NULL, 0, NULL);
        if(isAttacking) {
            return;
        }
        isAttacking = true;
        attackFrameIndex = 0;
        attackAnimCounter = 0;

        int jarakserangdekat = 20;
        
        int enemyBox_kiri = p2.x;
        int enemyBox_kanan = p2.x + p2.spriteWidth;
        
        int attackbox_Kiri;
        int attackbox_Kanan;
        
        int jarak = 20;
        int damage = 5;
        bool terkena = false;
        
        if(menghadapkanan) {
            attackbox_Kiri = x + spriteWidth/2;
            attackbox_Kanan = attackbox_Kiri + jarakserangdekat;
        } else {
            attackbox_Kiri = x-jarakserangdekat;
            attackbox_Kanan = x + spriteWidth/2;
        }
        
        if(attackbox_Kiri<enemyBox_kanan && attackbox_Kanan > enemyBox_kiri) {
            terkena = true;
        }
        
        bool tinggiserangan = (p2.y + p2.spriteWidth > y) && (p2.y< y + spriteHeight);
        
        if(terkena && tinggiserangan) {
            p2.health -= damage;
        }
    }
    
    void gerakkanan() {
        menghadapkanan = true;
        x += 10;
        if (x > 1200) {
            x = 0;
        }
        jalan = true;
    }
    
    bool diatastanah() {
        return y >= (690 - spriteHeight);
    }
    
    void gerakkiri() {
        menghadapkanan = false;
        x -= 10;
        if (x < 0) {
            x = 0;
        }
        jalan = true;
    }
    
    void naik() {
        cek_y = y;
        if (y > 0 + 20) {
            y -= 10;
        }
        jalan = true;
    }
    
    void turun() {
        y += 10;
        if (y > 570) {
            y = 570;
        }
        jalan = true;
    }
    
    void tembakPeluru() {
        mciSendString("play sfx_tembak from 0", NULL, 0, NULL);
        for (int i = 0; i < 5; i++) {
            if (peluruAktif[i] == 0) {
                peluruX[i] = x + 44;
                peluruY[i] = y + 80;
                peluruAktif[i] = 1;
                break;
            }
        }
    }
    
    void tembakPeluru1() {
        mciSendString("play sfx_tembak from 0", NULL, 0, NULL);
        for (int a = 0; a < 5; a++) {
            if (peluruAktif1[a] == 0) {
                peluruX1[a] = x + 46;
                peluruY1[a] = y + 80;
                peluruAktif1[a] = 1;
                break;
            }
        }
    }
    
    void gerakPeluru() {
        for (int i = 0; i < 5; i++) {
            if (peluruAktif[i] == 1) {
                peluruX[i] += 20;
                if (peluruX[i] > getmaxx()) {
                    peluruAktif[i] = 0;
                }
            }
        }
    }
    
    void gerakPeluru1() {
        for (int a = 0; a < 5; a++) {
            if (peluruAktif1[a] == 1) {
                peluruX1[a] -= 20;
                if (peluruX1[a] < 0) {
                    peluruAktif1[a] = 0;
                }
            }
        }
    }
    
    void drawPeluru() {
        setcolor(RED);
        for (int i = 0; i < 5; i++) {
            if (peluruAktif[i] == 1) {
                circle(peluruX[i], peluruY[i], 5);
                setfillstyle(SOLID_FILL, RED);
                floodfill(peluruX[i], peluruY[i], RED);
            }
        }
    }
    
    void drawPeluru1() {
        setcolor(RED);
        for (int a = 0; a < 5; a++) {
            if (peluruAktif1[a] == 1) {
                circle(peluruX1[a], peluruY1[a], 5);
                setfillstyle(SOLID_FILL, RED);
                floodfill(peluruX1[a], peluruY1[a], RED);
            }
        }
    }
    
    bool checkkenapijakan(player1& p1, tpijakan pijak[], int jumlah_pijakan) {
        for (int i = 0; i < jumlah_pijakan; ++i) {
            if (p1.x > pijak[i].x1 && p1.x < pijak[i].x2) {
                if (p1.y + 120 >= pijak[i].y1 && p1.y + 120 <= pijak[i].y1 + 10) {
                    p1.y = pijak[i].y1 - 120;
                    return true;
                }
            }
        }
        return false;
    }
    
    bool checksampingpijakan(player1& p1, tpijakan pijak[], int jumlah_pijakan) {
        for (int i = 0; i < jumlah_pijakan; ++i) {
            if (p1.y + 120 > pijak[i].y1 && p1.y + 20 < pijak[i].y2 && p1.x  > pijak[i].x1 && p1.x < pijak[i].x2) {
                return true;
            }
        }
        return false;
    }
    
    bool checkkenakepala(player1& p1, tpijakan pijak[], int jumlah_pijakan) {
        for (int i = 0; i < jumlah_pijakan; i++) {
            if (p1.x > pijak[i].x1 && p1.x < pijak[i].x2) {
                if (p1.cek_y + 60> pijak[i].y2 && p1.y + 60 <= pijak[i].y2) {
                    p1.y = pijak[i].y2 + 20;
                    return true;
                }
            }
        }
        return false;
    }
    void checkkenapeluruKanan(Musuhutama& p2) {
        for (int i = 0; i < 5; i++) {
            if (peluruAktif[i]) {
                int hitboxkiri= p2.x - (p2.hitboxWidth / 2);
                int hitboxkanan = p2.x + (p2.hitboxWidth / 2);

                if (peluruX[i] >= hitboxkiri && peluruX[i]<= hitboxkanan &&
                    peluruY[i] >= p2.y && peluruY[i] <= p2.y + p2.spriteHeight) {
                    p2.health -= 5;
                    peluruAktif[i] = 0;
                }
            }
        }
    }

    void checkkenapelurukiri(Musuhutama& p2) {
        for (int i = 0; i < 5; i++) {
            if (peluruAktif1[i]) {
                int hitboxkiri = p2.x - (p2.hitboxWidth / 2);
                int hitboxkanan = p2.x + (p2.hitboxWidth / 2);
                if (peluruX1[i] >= hitboxkiri && peluruX1[i] <= hitboxkanan &&
                peluruY1[i] >= p2.y && peluruY1[i]<= p2.y +p2.spriteHeight) {
                    p2.health -= 5;
                    peluruAktif1[i] = 0;
                }
            }
        }
    }
    
    
};

void Musuhutama::updateSerangan(player1& p1) {
    if(!nyeranglagi) {
        cooldownattack--;
        if(cooldownattack <= 0) {
            nyeranglagi = true;
        }
        return;
    }
    
    if (p1.x > x) {
        menghadapkanan = true;
        kakikirimaju = true;
    } else {
        menghadapkanan = false;
        kakikirimaju = false;
    }
    
    bool dalam_jangkauan = (std::abs((p1.x + p1.spriteWidth/2) - (this->x + this->spriteWidth/2)) < 50);
    this->menyerang = dalam_jangkauan;
    
    if (!dalam_jangkauan) {
        return;
    }
    
    bool bersentuhan = (this->x < p1.x + p1.spriteWidth &&
                        this->x + this->spriteWidth > p1.x &&
                        this->y < p1.y + p1.spriteHeight &&
                        this->y + this->spriteHeight > p1.y);
    
    if(bersentuhan && nyeranglagi) {
        p1.health -= 10;
        nyeranglagi = false;
        cooldownattack = attackCooldown;
    }
}

void mainMenu() {
    void* main_menu = malloc(imagesize(0, 0, 1200, 750));
    
    if (main_menu == NULL) {
        printf("Gagal mengalokasikan memori untuk menu!");
        return;
    }
    
    readimagefile("background/mainmenu.gif", 0, 0, 1200, 750);
    getimage(0, 0, 1200, 750, main_menu);
     mciSendString("play menuBGM repeat", NULL, 0, NULL);
    
    int page = 0;
    while (true) {
        setactivepage(page);
        cleardevice();
        putimage(0, 0, main_menu, COPY_PUT);
        
        settextstyle(BOLD_FONT, HORIZ_DIR, 6);
        setcolor(YELLOW);
        settextjustify(CENTER_TEXT, CENTER_TEXT);
        outtextxy(getmaxx() / 2, getmaxy() / 2 - 150, "THE ODYSSEY OF EROS");
        
        settextstyle(DEFAULT_FONT, HORIZ_DIR, 4);
        setcolor(WHITE);
        outtextxy(getmaxx() / 2, getmaxy() / 2 + 20, "1. Start Game");
        outtextxy(getmaxx() / 2, getmaxy() / 2 + 80, "2. Exit");
        
        setvisualpage(page);
        page = 1 - page;
        
        if (kbhit()) {
            char choice = getch();
            if(choice == '1' || choice == '2') {
                mciSendString("stop menuBGM", NULL, 0, NULL);
            }
            if (choice == '1') {
                free(main_menu);
                return;
            } else if (choice == '2') {
                free(main_menu);
                closegraph();
                exit(0);
            }
        }
        delay(100);
    }
}

int main() {
    initwindow(1200, 750, "THE_ODYSSEY_OF_EROS");
      mciSendString("open \"Backsound/Iwan Gabovitch - Dark Ambience Loop.mp3\" alias menuBGM", NULL, 0, NULL);
    mciSendString("open \"Backsound/Iwan Gabovitch - Dark Ambience Loop.mp3\" alias gameBGM", NULL, 0, NULL);
    mciSendString("open \"Backsound/086409_retro-gun-shot-81545.mp3\" alias sfx_tembak", NULL, 0, NULL);
    mciSendString("open \"Backsound/running-14658.mp3\" alias sfx_lari", NULL, 0, NULL);
    mciSendString("open \"Backsound/sword-slash-and-swing-185432.mp3\" alias sfx_serang", NULL, 0, NULL);
    mciSendString("open \"Backsound/game-over-classic-206486.mp3\" alias sfx_over", NULL, 0, NULL);

    
    mainMenu();
    mciSendString("play gameBGM repeat", NULL, 0, NULL);
    int hal = 0;
    int lebarplayer = 84;
    int tinggiplayer = 120;
    bool game_over = false;
    bool suaragameover = false;
    

    
    void* gambar_belakang = malloc(imagesize(0, 0, 1200, 750));
    if (gambar_belakang == NULL) {
        printf("Gagal mengalokasikan memori untuk background game!");
        closegraph();
        return -1;
    }
    
    const int jumlah_pijakan = 5;
    tpijakan pijakan[] = {
        tpijakan(-1, 180), tpijakan(-1, 500),
        tpijakan(950, 180), tpijakan(950, 500),
        tpijakan(470, 340),
    };
    
    tlindung1 l; tlindung2 z; tlindung3 o; tlindung4 f;
    tlindungtengah1 x; tlindungtengah2 v; tanah u;
    player1 p1(100, 570);
    Musuhutama p2(1100, 570);
    
    p1.loadsprites("Gambar_Game/Run.gif", "Gambar_Game/Run_masking_(2).gif",
        "Gambar_Game/Run_mirror.gif", "Gambar_Game/Run_mirror_masking_2.gif",
        "Gambar_Game/Run_musuh.gif", "Gambar_Game/run_Masking_Musuh.gif",
        "Gambar_Game/Run_musuh_kiri.gif", "Gambar_Game/run_Masking_Musuh_kiri.gif",
        "Gambar_Game/Attack_Musuh.gif", "Gambar_Game/attack_masking_musuh.gif",
        "Gambar_Game/Attack_Musuh_kiri.gif", "Gambar_Game/attack_masking_musuh_kiri.gif");
    p1.pakesrpite = true;
    
    setactivepage(2);
    readimagefile("Gambar_Game/back.gif", 0, 0, 1200, 750);
    readimagefile("Gambar_game/buildings.gif", 0, 0, 1200, 750);
    readimagefile("Gambar_game/front.gif", 0, 0, 1200, 750);
    u.draw(); l.draw(); z.draw(); o.draw(); f.draw();
    for (int i = 0; i < jumlah_pijakan; i++) {
        pijakan[i].draw();
    }
    x.draw(); v.draw();
    getimage(0, 0, 1200, 750, gambar_belakang);
    
    setactivepage(0); cleardevice();
    setactivepage(1); cleardevice();
    
    bool spasi_sebelum_dipencet = false;
    bool J_seebelum_dipencet = false;
    
    while (true) {
        setactivepage(hal);
        cleardevice();
        putimage(0, 0, gambar_belakang, COPY_PUT);
        
        if (game_over) {
            if (!suaragameover) {
        mciSendString("stop gameBGM", NULL, 0, NULL); 
        mciSendString("play sfx_over from 0", NULL, 0, NULL);
            suaragameover = true; 
    }
            settextstyle(BOLD_FONT, HORIZ_DIR, 8);
            setcolor(RED);
            settextjustify(CENTER_TEXT, CENTER_TEXT);
            outtextxy(getmaxx() / 2, getmaxy() / 2, "GAME OVER");
            settextstyle(BOLD_FONT, HORIZ_DIR, 4);
            outtextxy(getmaxx() / 2, getmaxy() / 2 + 60, "Press ESC to exit");
            
            if (GetAsyncKeyState(VK_ESCAPE)) {
                break;
            }
        } else {
            if (GetAsyncKeyState(VK_ESCAPE)) { break; }
            
            if(GetAsyncKeyState('1')) {
                p1.modeserang = 1;
            }
            if(GetAsyncKeyState('2')) {
                p1.modeserang = 2;
            }
            
            bool isMoving = GetAsyncKeyState('D') || GetAsyncKeyState('A');
            p1.jalan = isMoving;

            if(p1.jalan && !p1.suaralari && p1.diatastanah()) {
                mciSendString("play sfx_lari repeat ", NULL, 0, NULL);
                p1.suaralari = true;
            } else if(!p1.jalan && p1.suaralari && !p1.diatastanah()) {
                mciSendString("stop sfx_lari", NULL, 0, NULL);
                p1.suaralari = false;
            }
            
            if (GetAsyncKeyState('D') && !p1.checksampingpijakan(p1, pijakan, jumlah_pijakan))
                p1.gerakkanan();
            
            if (GetAsyncKeyState('A') && !p1.checksampingpijakan(p1, pijakan, jumlah_pijakan))
                p1.gerakkiri();
            
            if (GetAsyncKeyState('W') && !p1.checkkenakepala(p1, pijakan, jumlah_pijakan))
                p1.naik();
            
            if (GetAsyncKeyState('S') && !p1.diatastanah() && !p1.checkkenapijakan(p1, pijakan, jumlah_pijakan))
                p1.turun();
            
            bool spasi_ditekan = GetAsyncKeyState(VK_SPACE);
            if (spasi_ditekan && !spasi_sebelum_dipencet) {
                if(p1.modeserang==2) {
                    p1.tembakPeluru();
                } else if(p1.modeserang==1) {
                    p1.seranganjarakdekat(p2);
                }
            }
            spasi_sebelum_dipencet = spasi_ditekan;
            
            bool J_ditekan = GetAsyncKeyState('J');
            if (J_ditekan && !J_seebelum_dipencet) {
            if(p1.modeserang==2) {
        
            if(!p1.menghadapkanan) {
            p1.tembakPeluru1(); 
            }
            } else if(p1.modeserang==1) {
            p1.seranganjarakdekat(p2);
            }
            }
            J_seebelum_dipencet = J_ditekan;

            
            p1.gerakPeluru();
            p1.gerakPeluru1();
            p2.gerakmusuh(p1.x);
            p2.updateSerangan(p1);
            p1.checkkenapeluruKanan(p2);
            p1.checkkenapelurukiri(p2);
            
            p1.drawPeluru();
            p1.drawPeluru1();
            p1.draw();
            p2.draw();
            p1.bar_darah();
            p2.bar_darah();
            
            if (p2.health <= 0) {
                p2.health = 0;
                game_over = true;
            }
            if (p1.health <= 0) {
                p1.health = 0;
                game_over = true;
            }
        }
        
        setvisualpage(hal);
        hal = 1 - hal;
        delay(30);
    }
     mciSendString("stop menuBGM", NULL, 0, NULL); 
    mciSendString("stop gameBGM", NULL, 0, NULL);
    mciSendString("stop sfx_lari", NULL, 0, NULL);
    mciSendString("stop sfx_serang", NULL, 0, NULL);
    mciSendString("stop sfx_over", NULL, 0, NULL);
    
    mciSendString("close menuBGM", NULL, 0, NULL); 
    mciSendString("close gameBGM", NULL, 0, NULL);
    mciSendString("close sfx_tembak", NULL, 0, NULL);
    mciSendString("close sfx_lari", NULL, 0, NULL);
     mciSendString("close sfx_serang", NULL, 0, NULL); 
    mciSendString("close sfx_over", NULL, 0, NULL);
    
    free(gambar_belakang);
    closegraph();
    return 0;
}