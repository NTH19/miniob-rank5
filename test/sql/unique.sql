create table unique_table(id int, age int, name char, score float);
create index index_1 on unique_table(age);
create unique index index_2 on unique_table(id);
create unique index index_3 on unique_table(id, name);
create index index_4 on unique_table(name);
create unique index index_5 on unique_table(id, age);
create unique index index_6 on unique_table(age, name);

insert into unique_table values(1, 1, 'a', 1.0);
insert into unique_table values(2, 2, 'b', 2.0), (3, 3, 'c', 1.0), (4, 4, 'd', 4.0);


insert into unique_table values(1, 1, 'g', 1.0);

insert into unique_table values(5, 1, 'g', 1.0);

insert into unique_table values(6, 1, 'g', 1.0);

update unique_table set id = 7 where id = 6;

update unique_table set name = 'g' where id = 1;


