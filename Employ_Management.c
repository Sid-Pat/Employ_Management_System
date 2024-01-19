//Rudraksh Patil
#include <stdio.h>

long long end = -1;

struct emp {
  int empID;
  char firstName[50];
  char lastName[50];
  int salary;
  char joiningDate[20];
};

struct emp fields[105];

void addEmp() {
  end++;
  int i = end;
  scanf("%d", &fields[i].empID);
  scanf("%s", fields[i].firstName);
  scanf("%s", fields[i].lastName);
  scanf("%d", &fields[i].salary);
  scanf("%s", fields[i].joiningDate);

}

void delEmp(int n) {
  int del = -1;
  for (int i = 0; i <= end; i++) {
    if (fields[i].empID == n) {
      del = i;
      break;
    }
  }

  if (del != -1) {
    for (int i = del; i <= end; i++) {
      fields[i] = fields[i + 1];
    }
    end--;
  }
}

void display(int n) {
  int disp = -1;

  for (int i = 0; i <= end; i++) {
    if (fields[i].empID == n) {
      disp = i;
      break;
    }
  }
  if (disp != -1) {
    printf("%d ", fields[disp].empID);
    printf("%s ", fields[disp].firstName);
    printf("%s ", fields[disp].lastName);
    printf("%d ", fields[disp].salary);
    printf("%s\n", fields[disp].joiningDate);
  }
}


void displAll() {

int y = end+1;
  for (int k = 0; k < y - 1; k++)
  {
    for (int j = 0; j < y - k - 1; j++)
    {
      if (fields[j].empID > fields[j + 1].empID)
      {
          
          fields[104] = fields[j];
          fields[j] = fields[j + 1];
          fields[j + 1] = fields[104];
      }
    }
  }


  for (int i = 0; i <= end; i++) {
    printf("%d ", fields[i].empID);
    printf("%s ", fields[i].firstName);
    printf("%s ", fields[i].lastName);
    printf("%d ", fields[i].salary);
    printf("%s\n", fields[i].joiningDate);
  }
}

void update(int n, int NewSalary) {
  int update = -1;
  for (int i = 0; i <= end; i++) {
    if (fields[i].empID == n) {
      update = i;
      break;
    }
  }
  if (update != -1) {
    fields[update].salary = NewSalary;
  }
}

void mmm() {
  int sum = 0;
  int min = fields[0].salary;
  int max = fields[0].salary;

  for (int i = 0; i <= end; i++) {
    sum = sum + fields[i].salary;
    if (min > fields[i].salary) {
      min = fields[i].salary;
    }
    if (max < fields[i].salary) {
      max = fields[i].salary;
    }
  }
  float mean = sum / (end + 1);
  printf("%d %d %.2f\n", min, max, mean);
}
void date() {
  char r[20];
  int cnt = 0;
  scanf("%s", r);
  long long x = (r[6] - '0') * 10000000 + (r[7] - '0') * 1000000 +
                (r[8] - '0') * 100000 + (r[9] - '0') * 10000 +
                (r[3] - '0') * 1000 + (r[4] - '0') * 100 + (r[0] - '0') * 10 +
                (r[1] - '0');
  for (int i = 0; i <= end; i++) {
    char p[20];
    for (int j = 0; j < 20; j++) {
      p[j] = fields[i].joiningDate[j];
    }
    long long y = (p[6] - '0') * 10000000 + (p[7] - '0') * 1000000 +
                  (p[8] - '0') * 100000 + (p[9] - '0') * 10000 +
                  (p[3] - '0') * 1000 + (p[4] - '0') * 100 + (p[0] - '0') * 10 +
                  (p[1] - '0');
    if (y > x) {
    } else {
      cnt++;
    }
  }
  printf("%d\n", cnt);
}
int main(void) {
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    int task;
    scanf("%d", &task);

    if (task == 1) {
      addEmp();
    } else if (task == 2) {
      int delID;
      scanf("%d", &delID);
      delEmp(delID);
    } else if (task == 3) {
      int dispID;
      scanf("%d", &dispID);
      display(dispID);
    } else if (task == 4) {
      displAll();
    } else if (task == 5) {
      int updID, newSal;
      scanf("%d %d", &updID, &newSal);
      update(updID, newSal);
    } else if (task == 6) {
      mmm();
    }

    else if (task == 7) {
      date();
    }
  }


}