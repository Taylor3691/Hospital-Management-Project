# UPDATE Cho task 1805

## 2. Class  RegistrationService
### a. Thuộc tính
- `_patientRepo`: IPatientRepository*
- `_medicalRecordRepo`: IMedicalRecordRepository*
- `_roomRepo`: IRoomRepository*

### b. Phương thức
- MedicalRecord* createMedicalRecord(patientId)
- Patient* createPatient(id, name, gender, address, phone, brithday, allergies)
- HeathInsuracne* createInsurace(id, startDate, endDate, rate)
- void assignInsurace(patientId, HeathInsurance*)
- void assignRoom(roomId, recordId)
- void refreshRoomWaiting()
- void goToExaminationSerivce()
## 2. Class ExamiantionService
### a. Thuộc tính
- `_medicalRecordRepo`: IMedicalRecordRepository*
- `_employeeRepo`: IEmployeeRepository*
- `_medicineRepo`: IMedicineRepository*
- `_clinicalTestRepo`: ITestServiceRepoistory*
- `_receiptRepository`: IReceiptRepository*
- `_roomRepository`: IRoomExaminationRepository*
### b. Phương thức
- void assginDoctor(id)
- void prescribe(recordId, medicineId, quantity)
- void addClinicalTest(recordId, testId)
- void setDiagnosis(string res)
- void goToTestProcessingService()
- void goToBillService(medicalRecordId)
## 3. Class TestProcessingService
### a. Thuộc tính
`_medicalRecordRepo`: IMedicalRecordRepository*
`_testRepository`: ITestServiceRepositry*
### b. Phương thức
- void assginResult(medicalId, testId, result)
- void goToExaminationSerivce()
## 4. Class BillService
### a. Thuộc tính
`_receiptRepository`: IReceiptRepository*
`_patientRepository`: IPatientRepository*
### b. Phương thức
- double total(medicalRecordId)
- double afferApplyPayingMedthod(medicalRecordId)
- void showAllBillableItem()

