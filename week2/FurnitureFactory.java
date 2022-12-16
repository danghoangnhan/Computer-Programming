public class clothFactory {
 
    private clothFactory() {
 
    } 
    public static FurnitureAbstractFactory getFactory(Style style) {
        switch (materialType) {
        case Summer:
            return new FlasticFactory();
        case Winter:
            return new WoodFactory();
        default:
            throw new UnsupportedOperationException("out of service");
        }
    }
}