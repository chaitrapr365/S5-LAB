--create table Patient(PID number primary key,PNAME varchar2(20),ADDR_NAMES varchar2(50));
--insert into Patient VALUES(0003,'Angel Shaju','ERNAKULAM');
--insert into Patient VALUES(1232,'Robert Peter','KOZHIKODE');
--insert into Patient VALUES(1666,'Shalini Mathew','ALAPUZHA');
--insert into Patient VALUES(4432,'Jimmy Kurian','MALAPURAM');
--create table PDetails(PID number,foreign key(PID) references Patient,Disease varchar2(20),Doctor_name varchar2(20),Admit_date DATE,Discharged  varchar2(5),Amount_paid int);
--insert into PDetails VALUES(0003,'LEG FRACTURE','DR.ISAAC JOHN','03-FEB-22','NO',10000);
--insert into PDetails VALUES(1232,'DIALYSIS','DR.SHALI KUMAR','18-FEB-22','NO',23331);
--insert into PDetails VALUES(1666,'SNAKE BITE','DR.SREERAJ NAIR','10-FEB-22','NULL',50000);
--insert into PDetails VALUES(4432,'FOOD POISIONING','DR.ISAAC JOHN','10-FEB-22','NULL',15000);
--create table History_table(PID number,foreign key(PID) references Patient,Pname varchar2(20),Address varchar2(50),Disease varchar2(20),Doctor_name varchar2(20),Discharge varchar2(5));
CREATE OR REPLACE TRIGGER p_trigger
AFTER UPDATE ON PDETAILS
FOR EACH ROW
WHEN (NEW.DISCHARGED='YES')

DECLARE
	pn PATIENT.PNAME%type;
	ad PATIENT.ADDR_NAMES%type;
BEGIN
	SELECT PNAME,ADDR_NAMES into pn,ad FROM PATIENT WHERE PID=:OLD.PID;
	INSERT INTO HISTORY VALUES(:OLD.PID,PN,AD,:OLD.DISEASE,:OLD.DOCTOR,:NEW.DISCHARGED);
     dbms_output.put_line('patient' || PN ||'discharged');
END;
