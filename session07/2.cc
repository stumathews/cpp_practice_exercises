
			Employee
			  name
			  NI
			/       \
	   HourlyEmployee       ComissionedEmployee
			\       /
		      BothEmployee


		      This would mean Employee would be replicated twice in BothEmployee.
		      In order for a BothEmployee to have the same interface as Employee, it would need to 
		      use inheritance. It would need to use virtual inheritance to avoid Employee class existing twice
		      on BothEmployee via one from HourlyEmployee and one from ComissionedEmployeed

		      HourlyEmployee : virtual Employee
		      	ctor: HourlyEmploee()
		      ComissionedEmployee : virtual Employee
		        ctor: ComissionedEmployee()
		      BothEmployee : public HourltEmployee, public ComissionedEmploee
		      	ctor: BothEmployee() 

