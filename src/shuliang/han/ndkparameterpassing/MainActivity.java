package shuliang.han.ndkparameterpassing;

import android.os.Bundle;
import android.app.Activity;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Toast;
import android.support.v4.app.NavUtils;

public class MainActivity extends Activity {

	static{
		System.loadLibrary("DataProvider");
	}
	
	DataProvider dataProvider;
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        dataProvider = new DataProvider();
    }

    public void onClick(View view) {
    	
    	int id = view.getId();
    	
    	switch (id) {
			case R.id.add:
				int result = dataProvider.add(1, 2);
				Toast.makeText(getApplicationContext(), "the add result : " + result, Toast.LENGTH_LONG).show();
				break;
				
			case R.id.sayHelloInc:
				Toast.makeText(getApplicationContext(), dataProvider.sayHelloInc("Hello"), Toast.LENGTH_LONG).show();
				break;
				
			case R.id.intMethod:
				int[] array = {1, 2, 3, 4, 5};
				dataProvider.intMethod(array);
				break;
	
			default:
				break;
		}
	}

    
}
