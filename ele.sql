SET SERVEROUTPUT ON;
CREATE TABLE BILL(CUSTOMER_NO number PRIMARY KEY,NAME varchar(20),PRESENT_READING number,PREVIOUS_READING number);
INSERT INTO BILL VALUES(1223,'CAROLINE MARY',290,70);
INSERT INTO BILL VALUES(1364,'DANIEL ALEX',360,50);
INSERT INTO BILL VALUES(4511,'CHAITRA',333,80);
INSERT INTO BILL VALUES(5665,'ELSA THOMAS',100,50);
INSERT INTO BILL VALUES(1224,'CAROLINE MARY',250,100);
DECLARE
    cust_no BILL.CUSTOMER_NO%type;
    prev_read BILL.PRESENT_READING%type;
    curr_read BILL.PREVIOUS_READING%type;
    cursor ebill is 
        select CUSTOMER_NO,PRESENT_READING,PREVIOUS_READING from BILL;
    amount number;
    diff number;
BEGIN
    open ebill;
    loop
    		fetch ebill into cust_no,curr_read,prev_read;
    		EXIT WHEN ebill%notfound;
    		diff:=curr_read-prev_read;
    		if(diff<=50) then
    			amount:=5*diff;
    		elsif(diff between 51 and 100) then
    			amount:=(5*50)+(10*(diff-50));
    		elsif(diff between 101 and 200) then
    			amount:=(5*50)+(10*50)+(15*(diff-100));
    		else 
    			amount:=(5*50)+(10*50)+(15*100)+(20*(diff-200));
    		end if;
    		dbms_output.put_line('Customer no='||cust_no||' Current reading='||curr_read||' Previous reading='||prev_read||' AMOUNT='||amount||'  CONSUMPTION='||diff);
    	end loop;
    	close ebill;
END;

    		
