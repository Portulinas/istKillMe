package calc;

import javax.jws.WebService;

@WebService(
    endpointInterface="calc.CalcPortType",
    wsdlLocation="Calc.wsdl",
    name="Calc",
    portName="CalcPort",
    targetNamespace="urn:calc",
    serviceName="CalcService"
)
public class CalcPort implements CalcPortType {
	
	@Override
	public int sum(int a, int b){
		return a + b;
	}
	
	@Override
	public int sub(int a, int b){
		return a - b;
	}
	
	@Override
	public int mult(int a, int b){
		return a * b;
	}
	
	@Override
	public int intdiv(int a, int b) throws DivideByZero{
		if (b == 0){
			throw new DivideByZero("cannot devide by zero!", new DivideByZeroType());
		}
		return a / b;
	}
	
}
