void fuzzy() {
//coding Perhitungan Fuzzy
  float kur, kus, kut, sur, sus, sut;
  float ku1, ku2, ku3, ku4, ku5, ku6, ku7, ku8, ku9;
  float nu, chr, chs, cht, nur, nus, nut, ktr, kts, ktt;
  float chr1, chr2, chr3, chr4, chr5, chr6, chr7, chr8, chr9, chs1, chs2,
        chs3, chs4, chs5, chs6, chs7, chs8, chs9, cht1, cht2, cht3, cht4, cht5,
        cht6, cht7, cht8, cht9;

    if (ku <= 40){kur=1;}
    else if (ku <= 45){kur = (45-ku)/(45-40);}
    else {kur = 0;}
    
    if (ku <= 40 or ku >= 70){kus = 0;}
    else if (ku <= 45){kus = (ku-40)/(45-40);}
    else if (ku >= 65){kus = (70-ku)/(70-65);}
    else {kus = 1;}
    
    if(ku <=65){kut = 0;}
    else if (ku <=70){ kut=(ku-65)/(70-65);}
    else {kut = 1;}
    
    if (su <= 22){sur = 1;}
    else if (su <= 25){sur = (25-50)/(25-22);}
    else {sur = 0;}
    
    if (su<= 22 or su>= 36){sus = 0;}
    else if (su <= 29){sus = (su-22)/(29-22);}
    else if (su >= 29){sus = (36-su)/(36-29);}
       
    if (su <= 33){sut = 0;}
    else if (su<= 38){sut = (su-33)/(38-33);}
    else {sut = 1;}
    
    ku1 = min(kut,sur); 
    ku2 = min(kus,sur); 
    ku3 = min(kur,sur);
    ku4 = min(kut,sus); 
    ku5 = min(kus,sus); 
    ku6 = min(kur,sus);
    ku7 = min(kut,sut); 
    ku8 = min(kus,sut); 
    ku9 = min(kur,sut);

    nu = (ku1*0.3+ku2*0.3+ku3*0.6+ku4*0.3+ku5*0.6+ku6*0.9+ku7*0.6+ku8*0.9+ku9*0.9)/(ku1+ku2+ku3+ku4+ku5+ku6+ku7+ku8+ku9)*100;

    if (ch <= 40){chr=1;}
    else if (ch <= 45){chr = (45-ch)/(45-40);}
    else {chr = 0;}
    
    if (ch <= 40 or ch >= 70){chs = 0;}
    else if (ch <= 45){chs = (ch-40)/(45-40);}
    else if (ch >= 65){chs = (70-ch)/(70-65);}
    else {chs = 1;}
    
    if(ch <=65){cht = 0;}
    else if (ch <=70){ cht=(ch-65)/(70-65);}
    else {cht = 1;}
       
    if (kth <= 55){ktr=1;}
    else if (kth <= 60){ktr = (60-kth)/(60-55);}
    else {ktr = 0;}
    
    if (kth <= 55 or kth >= 70){kts = 0;}
    else if (kth <= 60){kts = (kth-55)/(60-55);}
    else if (kth >= 65){kts = (70-kth)/(70-65);}
    else {kts = 1;}
    
    if(kth <=65){ktt = 0;}
    else if (kth <=70){ ktt=(kth-65)/(70-65);}
    else {ktt = 1;}
    
    if (nu <= 30){nur=1;}
    else if (nu <= 60){nur = (60-nu)/(60-30);}
    else {nur = 0;}
    
    if (nu<= 30 or nu>= 90){nus = 0;}
    else if (nu <= 60){nus = (nu-30)/(60-30);}
    else if (nu >= 60){nus = (90-nu)/(90-60);}
    
    if(nu <=60){nut = 0;}
    else if (nu <=90){ nut=(nu-60)/(90-60);}
    else {nut = 1;}
       
    chr1 =  min(min(ktr ,nur ), chr)*0.9;
    chr2 =  min(min(kts ,nur ), chr)*0.6;
    chr3 =  min(min(ktt ,nur ), chr)*0.6;
    chr4 =  min(min(ktr ,nus ), chr)*0.6;
    chr5 =  min(min(kts ,nus ), chr)*0.6;
    chr6 =  min(min(ktt ,nus ), chr)*0.6;
    chr7 =  min(min(ktr ,nut ), chr)*0.9;
    chr8 =  min(min(kts ,nut ), chr)*0.9;
    chr9 =  min(min(ktt ,nut ), chr)*0.6;
    
    chs1 =  min(min(ktr ,nur ), chs)*0.6;
    chs2 =  min(min(kts ,nur ), chs)*0.3;
    chs3 =  min(min(ktt ,nur ), chs)*0.3;
    chs4 =  min(min(ktr ,nus ), chs)*0.6;
    chs5 =  min(min(kts ,nus ), chs)*0.6;
    chs6 =  min(min(ktt ,nus ), chs)*0.6;
    chs7 =  min(min(ktr ,nut ), chs)*0.6;
    chs8 =  min(min(kts ,nut ), chs)*0.6;
    chs9 =  min(min(ktt ,nut ), chs)*0.6;
    
    cht1 =  min(min(ktr ,nur ), cht)*0.3;
    cht2 =  min(min(kts ,nur ), cht)*0.3;
    cht3 =  min(min(ktt ,nur ), cht)*0.3;
    cht4 =  min(min(ktr ,nus ), cht)*0.6;
    cht5 =  min(min(kts ,nus ), cht)*0.3;
    cht6 =  min(min(ktt ,nus ), cht)*0.3;
    cht7 =  min(min(ktr ,nut ), cht)*0.6;
    cht8 =  min(min(kts ,nut ), cht)*0.6;
    cht9 =  min(min(ktt ,nut ), cht)*0.6;
     
    Zch1 = chr1+ chr2+ chr3+ chr4+ chr5+ chr6+ chr7+ chr8+ chr9+ chs1+ chs2+
    chs3+ chs4+ chs5+ chs6+ chs7+ chs8+ chs9+ cht1+ cht2+ cht3+ cht4+ cht5+
    cht6+ cht7+ cht8+ cht9;
       
    chr1 =  min(min(ktr ,nur ), chr);
    chr2 =  min(min(kts ,nur ), chr);
    chr3 =  min(min(ktt ,nur ), chr);
    chr4 =  min(min(ktr ,nus ), chr);
    chr5 =  min(min(kts ,nus ), chr);
    chr6 =  min(min(ktt ,nus ), chr);
    chr7 =  min(min(ktr ,nut ), chr);
    chr8 =  min(min(kts ,nut ), chr);
    chr9 =  min(min(ktt ,nut ), chr);
    
    chs1 =  min(min(ktr ,nur ), chs);
    chs2 =  min(min(kts ,nur ), chs);
    chs3 =  min(min(ktt ,nur ), chs);
    chs4 =  min(min(ktr ,nus ), chs);
    chs5 =  min(min(kts ,nus ), chs);
    chs6 =  min(min(ktt ,nus ), chs);
    chs7 =  min(min(ktr ,nut ), chs);
    chs8 =  min(min(kts ,nut ), chs);
    chs9 =  min(min(ktt ,nut ), chs);
    
    cht1 =  min(min(ktr ,nur ), cht);
    cht2 =  min(min(kts ,nur ), cht);
    cht3 =  min(min(ktt ,nur ), cht);
    cht4 =  min(min(ktr ,nus ), cht);
    cht5 =  min(min(kts ,nus ), cht);
    cht6 =  min(min(ktt ,nus ), cht);
    cht7 =  min(min(ktr ,nut ), cht);
    cht8 =  min(min(kts ,nut ), cht);
    cht9 =  min(min(ktt ,nut ), cht);
     
    Zch2 = chr1+ chr2+ chr3+ chr4+ chr5+ chr6+ chr7+ chr8+ chr9+ chs1+ chs2+
    chs3+ chs4+ chs5+ chs6+ chs7+ chs8+ chs9+ cht1+ cht2+ cht3+ cht4+ cht5+
    cht6+ cht7+ cht8+ cht9;
        
    Zch = Zch1/Zch2;
}
