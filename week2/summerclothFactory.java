public class summerclothFactory extends clothAbstractFactory{
 
    @Override
    public Mancloth custome() {
        return new Mancloth();
    }
 
    @Override
    public Womancloth custome() {
        return new Womancloth();
    }
 
}