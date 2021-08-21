
public class SimpleDate {

    private int day;
    private int month;
    private int year;

    public SimpleDate(int day, int month, int year) {
        this.day = day;
        this.month = month;
        this.year = year;
    }

    @Override
    public String toString() {
        return this.day + "." + this.month + "." + this.year;
    }

    public boolean before(SimpleDate compared) {
        if (this.year < compared.year) {
            return true;
        }

        if (this.year == compared.year && this.month < compared.month) {
            return true;
        }

        if (this.year == compared.year && this.month == compared.month &&
                 this.day < compared.day) {
            return true;
        }

        return false;
    }
    
    public void advance(){
        this.advance(1);
    }
    
    public void advance(int howManyDays){
        if(howManyDays > 0){
            if(howManyDays + this.day <= 30){
                this.day += howManyDays;
            } else {
                this.day = howManyDays - (30 - this.day);
                if(this.month == 12){
                    this.month = 1;
                    this.year++;
                } else {
                    this.month++;
                }
            }
        }
    }
    
    public SimpleDate afterNumberOfDays(int days){
        int newDay = this.day, newMonth = this.month, newYear = this.year;
        
        if(days > 0){
            if(days + newDay <= 30){
                newDay += days;
            } else {
                newDay = days - (30 - newDay);
                if(newMonth == 12){
                    newMonth = 1;
                    newYear++;
                } else {
                    newMonth++;
                }
            }
        }        
        SimpleDate newDate = new SimpleDate(newDay, newMonth, newYear);
        return newDate;
    }

}
