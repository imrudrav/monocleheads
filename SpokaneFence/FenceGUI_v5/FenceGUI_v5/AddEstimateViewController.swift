//
//  AddEstimateViewController.swift
//  FenceGUI_v5
//
//  Created by Tanner Orndorff on 8/1/18.
//  Copyright © 2018 Monocle Heads. All rights reserved.
//

import UIKit

class AddEstimateViewController: UIViewController, UITableViewDelegate, UITableViewDataSource  {
    
    var est: Estimate?
    var cus: Customer?
    @IBOutlet var namedata: UILabel?
    @IBOutlet var addressdata: UITextField?
    @IBOutlet var lineTable: UITableView?
    @IBOutlet var gateTable: UITableView?
    @IBOutlet var extraTable: UITableView?
    
    override func viewDidLoad() {
        super.viewDidLoad()

        // Do any additional setup after loading the view.
        lineTable?.dataSource = self
        lineTable?.delegate = self
        lineTable?.register(UITableViewCell.self, forCellReuseIdentifier: "linecell")
        
        
    }

    override func viewDidAppear(_ animated: Bool) {
        est = Estimate(id: 0, cid: "0", eid: "0", date: Date())
        namedata?.text = "New Estimate for \(cus?.fname ?? "Unknown") \(cus?.lname ?? "Customer")"
        addressdata?.text = cus?.address
    }
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    

    /*
    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        // Get the new view controller using segue.destinationViewController.
        // Pass the selected object to the new view controller.
    }
    */

    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        var count: Int?
        
        if tableView == self.lineTable {
            //need to create line class
        }
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        <#code#>
    }
}
