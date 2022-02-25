set serveroutput on;
DECLARE
  e_prevread ELECBILL.PREV_READING%type;
  e_presread ELECBILL.PRES_READING%type;
  e_cno ELECBILL.CNO%type;
  amount number;
  diff number;
  cursor e_elecbill is
    select PREV_READING,PRES_READING,CNO from ELECBILL;
BEGIN
  open e_elecbill;
  loop
    fetch e_elecbill into e_prevread,e_presread,e_cno;
    exit when e_elecbill%notfound;
    diff:=e_presread-e_prevread;
    if(diff<=50)then
     amount:=diff*5;
    elsif(diff<=100)then
     amount:=(50*5)+((diff-50)*10);
    elsif(diff<=200)then
     amount:=(50*5)+(50*10)+((diff-100)*15);
    else
     amount:=(50*5)+(50*10)+(100*15)+((diff-200)*20);
    end if;
    dbms_output.put_line('customer number= '||e_cno||' ,units= '||diff||' ,cost= '||amount);
  end loop;
  close e_elecbill;
end;

/*output
customer number= 5 ,units= 50 ,cost= 250
customer number= 3 ,units= 30 ,cost= 150
customer number= 7 ,units= 70 ,cost= 450

PL/SQL procedure successfully completed.

Commit complete.
*/
