package Utils;

public class ShortStringException extends Throwable {
    public ShortStringException() {
        super();
    }

    public ShortStringException(String message) {
        super(message);
    }

    public ShortStringException(String message, Throwable cause) {
        super(message, cause);
    }

    public ShortStringException(Throwable cause) {
        super(cause);
    }

}

