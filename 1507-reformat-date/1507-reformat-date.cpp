class Solution {
public:
   string fmonth(string month){
        if(month=="Jan") return "01";
        else if(month=="Feb") return "02";
        else if(month=="Mar") return "03";
        else if(month=="Apr") return "04";
        else if(month=="May") return "05";
        else if(month=="Jun") return "06";
        else if(month=="Jul") return "07";
        else if(month=="Aug") return "08";
        else if(month=="Sep") return "09";
        else if(month=="Oct") return "10";
        else if(month=="Nov") return "11";
        else  return "12";
    }
    string reformatDate(string date) {
        string day="";
        string month="";
        string year="";
        day+=date[0];
        if(isdigit(date[1]))
        day+=date[1];
        else {
            day="";
            day="0";
             day+=date[0];
             }
        int a=date.find(' ');
        month+=date.substr(a+1,3);
        int b=date.rfind(' ');
        year+=date.substr(b+1,4);
        return year+"-"+ fmonth(month)+"-"+day;
    }
};